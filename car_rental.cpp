#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
#include<math.h>
#include<random>


using namespace std;

// gloabal

vector<string> cars_avail = {"Honda", "Audi", "Volkswagen", "Civic", "Tailwind", "Tesla"};


class SysMain {
    private:
        int login_id;
        int admin_id;
    
    public : 
        string car_id;
        bool verified;
        bool confirm_admin;
        
        int user_id;
        int total_pay;

        void write_data(string data, string filename);
        bool admin_login(string);
        bool login(string);
        void menu(vector<string> &x);
        int rental(string, int, vector<string> &x);
        int payout(int, int);

        void admin_panel();

};


bool SysMain :: login(string creds){
    fstream records;

    records.open("my_rental.txt", ios::in);

    if (records){
        string rec_data;
        while (getline(records, rec_data)) {
            
            if (rec_data == creds){
                verified = true;
                cout<<"Successfully Logged in...";
                records.close();
                return true;

            
            }
        }

        cout<<"No User with that ID is currently registered...";

    }

    return false;

}

void SysMain :: menu(vector<string> &cars_avail){
    for (int i = 0; i < cars_avail.size(); i++)
    {
        cout<< i <<" <--> " << cars_avail[i];
    }
       
}

int SysMain :: rental(string car_info, int journey_length, vector<string> &cars_avail){
    for (size_t i = 0; i < cars_avail.size(); i++)
    {
       if (car_info == cars_avail[i]){
           payout(i, journey_length);
           cars_avail.erase(cars_avail.begin()+i);
           write_data(("RENTED" + car_id + to_string(login_id) + to_string(journey_length)), "my_rented.txt");
           cout<<"Your ride has been successfully rented...";
           
           return i;
       }
       else{
           cout<<"The ride you wish to rent is not available at the current moment...";
       }
    }

    return -1;

    
}

int SysMain :: payout(int car_index, int travel_length){

    int estd_ratio = (((travel_length/12.25) * 97.95) + (car_index * 125));

    total_pay = estd_ratio;
    return total_pay;

}

void SysMain :: write_data(string data, string filename){
    fstream write_rental;
    write_rental.open(filename, ios_base::app);

    if (write_rental){
        write_rental << (data);
        write_rental.close();

    }
    cout <<"Procedure Complete";

}



int main(){

    SysMain customer1;
    int travel_length = 323;
    if (customer1.login("329id&6%$dsas")){
        customer1.menu(cars_avail);
        int car_index = customer1.rental("Civic", travel_length, cars_avail);

        customer1.payout(car_index, travel_length);

    }


}

