#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {

public:

    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}

    
    virtual int get_price() {

        std::cout<<"Price of Hotelroom\n";
        return 50 * this->bedrooms_ + 100 * this->bathrooms_;
    }

private:

    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {

public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}


    int get_price() {
        std::cout<<"Price of Hotel Apartment \n";
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    // HotelRoom hr = HotelRoom(3, 1);
    // HotelApartment ha = HotelApartment(1,1);

    // std::cout<<hr.get_price();
    // std::cout<<ha.get_price();


    return 0;
}