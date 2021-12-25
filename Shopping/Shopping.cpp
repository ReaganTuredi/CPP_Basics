#include <iostream>         // cout, cin
#include <string>           
#include <unordered_map>    // for mapping items name to Item instance
#include <map>              // used for storing Item : item count pair
#include <cmath>            // std::round
#include <vector>           // for storing Store instances in Stores class
#include <istream>          // for reading stores / order from input file or std::cin
#include <sstream>          // for parsing items when reading file and storing output when ordering
#include <iomanip>          // formatted output
#include <fstream>          // used when reading happens from file instead of std::cin



/////////////////////////////////////////////////////////////////////////////////////
//
// Item price (and any price sum) should not have double inaccuracy errors,
// so instead of storing price as double, we store it as integer as follows:
// ex. 3.65 would be stored as 365
// following functions are used to convert double to integer and vice versa
//
//////////////////////////////////////////////////////////////////////////////////////

int doubleToInt(const double d){
    // turn price 4.50 to 450 so that no precision is lost
    return std::round(d * 100);
}

double intToDouble(const int i){
    // turn adjusted price of 450 to 4.50
    return double(i) / 100.0;
}


/////////////////////////////////////////////////////////////////////////////////////
//
// Item struct for storing item name, its price and the number of those items in inventory of the store.
//
//////////////////////////////////////////////////////////////////////////////////////

struct Item{
    std::string name;
    int count;
    int price;

    // default constructor (you need to have this one because of the maps)
    Item(){};

    // Constructor using Item attributes
    Item(const std::string& n, const int c, const int p){
        name = n;
        count = c;
        price = p;
    }

    // check if the count is empty (in which case the whole entry will be deleted, see Store class)
    bool isEmpty(){
        return count == 0;
    }

    // get price of item
    int getPrice(){
        return price;
    }

    // buy 's' of those objects, if available
    // if not, we will buy as much as possible
    // to indicate if any item was bought, we use reference to integer where number of bought items is stored
    // to get the price of the bought items more easily, we use another int reference to store the price of bought items
    void buy(const int c, int& boughtItems, int& boughtPrice){
        if(c < count){
            // we want less then is available, buy only c items
            boughtItems = c;
            boughtPrice = c * price;
            count -= c;
        }
        else{
            // we want more or same amount then is available, buy all they have
            boughtItems = count;
            boughtPrice = count * price;
            count = 0;
        }        
    }
};


/////////////////////////////////////////////////////////////////////////////////////
//
// Store structure hold data about individual store.
// Store has a name and location, and inventory which is storing pairs of item name : Item instance
// example of such pair: "Phone" : Item("Phone", 5, 20000)
//
//////////////////////////////////////////////////////////////////////////////////////

struct Store{
    std::string name;
    std::string location;
    // pairs of item name : Item instance, ex: "Phone" : Item("Phone", 5, 20000)
    std::unordered_map<std::string, Item> items; // unordered since order is not relevant

    // default constructor
    Store(){};

    // parametrized constructor
    Store(const std::string& n, const std::string& l){
        name = n;
        location = l;
    }

    // Adds new Item to the inventory
    void addItem(const std::string& name, int count, int price){
        items[name] = Item(name, count, price);
    }

    // checks if store has particular item in inventory
    bool has(const std::string& name){
        return items.count(name);
    }

    // works similarly to Item's buy method, but also checks if the store has the item in the first place
    // it also checks if the count of the item is 0 after the buying process is finished, if it is, whole Item entry is deleted from inventory
    void buy(const std::string& name, const int count, int &boughtItems, int& boughtPrice){
        if(has(name)){
            items[name].buy(count, boughtItems, boughtPrice);
            if(items[name].isEmpty()){
                // if buying the item lowered the count to 0, delete the whole entry.
                items.erase(name);
            }
        }
        else{
            boughtItems = 0;
            boughtPrice = 0;
        }
    }
    
    // print information about store (name and number of unique items)
    void print(){
        std::cout << name << " has " << items.size() << " distinct items.\n";
    }
};

/////////////////////////////////////////////////////////////////////////////////////
//
// Stores structure stores a vector of stores, allows you place orders and get info about items and prices accross stored stores
//
//////////////////////////////////////////////////////////////////////////////////////

struct Stores{
    std::vector<Store> stores;

    // create new Stores instance, since we get the data about the stores from file / cin, we pass istream from which we read the data
    Stores(std::istream& input){
        int count;
        std::string line;
        // first line contains info about how many stores there are
        input >> count;

        // dismiss rest of line
        std::getline(input, line);

        // read info about 'count' stores
        for(int i = 0; i < count; i++){
            std::string name, location;

            // get name and location
            std::getline(input, name);
            std::getline(input, location);
            Store s(name, location);

            // then read individual items till you read an empty line
            while(true){
                std::getline(input, line);
                // line empty means there are no more items, stop reading
                if(line == "" || line == " "){
                    break;
                }

                // otherwise turn the line to stringstream and parse the item name, count and price
                std::stringstream lineStream(line + "\n");
                std::string itemName, itemCount, itemPrice;
                std::getline(lineStream, itemName, ',');
                std::getline(lineStream, itemCount, ',');
                std::getline(lineStream, itemPrice);

                // price is in format "$13.50", remove the dollar sign with substr() -> "13.50",
                // turn the value to double -> 13.5, turn the double to int using custom function
                // finally add the item to store
                s.addItem(itemName, std::stoi(itemCount), doubleToInt(std::stod(itemPrice.substr(1))));
            }

            // add the whole store to stores vector
            stores.push_back(s);
        }
    }

    // print info about all stores by file order (which is easy as vector preserves insertion order)
    void printStores(){
        
        std::cout << "Store Related Information (ordered by in-file order):\nThere are " << stores.size() << " store(s).\n";
        for(Store store: stores){
            store.print();
        }
        std::cout << "\n";
    }

    // print items of all stores in aplhabetical order
    void printItems(){
        // using std::map here is perceft, you can store the name and its count,
        // but the map is also sutomatically sorted by the key, which in this case is the item name
        std::map<std::string, int> counter;

        for(Store store: stores){
            for(auto itemEntry: store.items){
                Item item = itemEntry.second;
                // is item is not in the map yet, create the entry with count = 0
                if(counter.count(item.name) == 0){
                    counter[item.name] = 0;
                }
                // add the count to map for given item name
                counter[item.name] += item.count;
            }
        }

        // print info from the map
        std::cout << "Item Related Information (ordered alphabetically):\n";
        std::cout << "There are " << counter.size() << " distinct item(s) available for purchase.\n";
        for(auto entry: counter){
            std::cout << "There are " << entry.second << " " << entry.first << "(s).\n";
        }
        std::cout << "\n";
    }

    // return index of the store in the vector, that offers cheapest item
    // if no store offers the item, -1 is returned
    int findCheapest(const std::string& name){

        // store the current minimum price and the index
        int price = -1;
        int resultIndex = -1;

        for(int i = 0; i < (int)stores.size(); i++){
            Store s = stores[i];

            // if store offers item and its price is lower or lowest price was not set yet,
            // replace the price and index
            if(s.has(name) && (s.items[name].getPrice() < price || price == -1 )){
                resultIndex = i;
                price = s.items[name].getPrice();
            }
        }
        return resultIndex;
    }

    // counts how many stores offer particular item
    int countStores(const std::string& name){
        int count = 0;
        for(Store &s: stores){
            if(s.has(name)){
                count++;
            }
        }
        return count;
    }

    // Order N items from stores, the stores will be selected so that the resulting price is as low as possible
    // returns total price of bought items
    int orderOne(const std::string& name, int count){
        std::cout << "Trying to order " << count << " " << name << "(s).\n";
        std::cout << countStores(name) << " store(s) sell " << name << ".\n";

        // as info about stores comes after final price, we will first accumulate this info
        // in stringstream, then we will print it after the price
        std::ostringstream orderLocations;
        int price = 0;
        int index;

        // count says how many items we still want to buy, we will look for 
        // stores as long as we want more and as long as the stores actually offer the item
        while(count > 0){
            
            // if no more items are in any store, look no more
            if ((index = findCheapest(name)) == -1){
                break;
            }

            // if some store that sells the item was found
            int boughtItems, boughtPrice;

            // buy up to count of those items (can be less if the store does not offer that many)
            // which is why we use boughtItems reference to calculate how many we did buy
            stores.at(index).buy(name, count, boughtItems, boughtPrice);

            // subtract how many you bought from count, add price of bought items to total price
            count -= boughtItems;
            price += boughtPrice;

            // and add info about the store where the item was bought + how many - to the stringstream, not to cout yet
            orderLocations << "Order " << boughtItems << " from " << stores.at(index).name << " in " << stores.at(index).location << "\n";
        }

        // once all items were bought (or stores ran out of it), display accumulated price and the info about the stores.
        std::cout << "Total price: $" << std::setprecision(2) << std::fixed << intToDouble(price) << "\n";
        std::cout << orderLocations.str() << "\n";
        return price;
    }

    // Order some items
    // once again uses input stream for input, could be a file stream or std::cin
    void order(std::istream& input){
        std::cout << "Shopping:\n";
        int count, total = 0;

        std::string line;
        input >> count;
        // get how manny items you wish to buy

        // dismiss rest of line
        std::getline(input, line);

        for(int i = 0; i < count; i++){
            int itemCount;
            std::string itemName;

            // item line has following format: 
            // "number name"
            // inpot >> int only read the number and leaves the space on input, which messes up std::getline
            // std::ws reads all whitespace
            input >> itemCount >> std::ws;
            std::getline(input, itemName);

            // get the info and order it
            total += orderOne(itemName, itemCount);
        }

        // print total price of whole order
        std::cout << "Be sure to bring $" << std::setprecision(2) << std::fixed << intToDouble(total) << " when you leave for the stores.\n";
    }
};





int main(int argc, char const *argv[]){
    // if parameter was passed, ex.: ./project.out file.txt
    // assume that the argument is the input file, in which case you open the file and use it as input
    if(argc == 2){
        std::ifstream input(argv[1]);

        //create stores
        Stores s(input);

        // print data about them and their items
        s.printStores();
        s.printItems();

        // get the order from the input file
        s.order(input);
        input.close();        
    }

    // if there was not such argument, get the input from std::cin
    else{
        Stores s(std::cin);
        s.printStores();
        s.printItems();
        s.order(std::cin);
    }
    
    return 0;
}
