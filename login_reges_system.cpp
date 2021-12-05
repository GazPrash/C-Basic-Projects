#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class System {
    private: 
        string sr_key;
        int username;
        int password;

    public:
        bool logged = false;

        void sr_key_generate();
        bool register_(string, string);
        void login_(string, string);
        void logout_();

};

void System :: sr_key_generate(){
    string alpha_numeric;

    string objects = "1234567890abcdefghijklmnoprstuvyzxwq";

    for (int i = 0; i < 16; i++)
    {
        alpha_numeric += (rand() % (objects.size()));
    }

    sr_key = alpha_numeric;

}

bool System :: register_(string user, string pass){
    fstream file_on;
    bool creds_valid;

    file_on.open("my_data.txt", ios::in);

    if (file_on) {
        string data;
        while (getline(file_on, data)){
            if (data != (user+"*"+pass)){
                creds_valid = true;
            }
            else{
                creds_valid = false;
                break;
            }
        }

        file_on.close();

    }

    if (creds_valid){
        file_on.open("my_data.txt", ios_base::app);

        if (file_on){
            file_on<<("\n" + user+"*"+pass);
            file_on.close();
            cout<<"User Successfully Created!";
            
            sr_key_generate();
            return true;
        }

    }

    
    return false;

}

void System :: login_(string user, string pass){
    if (!logged){
        fstream records;

        records.open("my_data.txt", ios::in);

        if (records){
            string data;
            while (getline(records, data)){
                if (data == (user +"*"+pass)){
                    logged = true;
                    cout<<"Successfully Logged In!";
                    break;

                }
                else{
                    // logged = false;
                    cout<<"No Account Registered...";
                }
                
            }

        }


    }
    else{
        cout<<"User is already logged in...";
    }
}

void System :: logout_(){
    if (logged){
        cout<<"You have successfully logged out";
    }
    else{
        cout<<"This function is currently unavailable because you are not logged in...";
    }

}



int main(){
    System user1;

    user1.register_("prashant", "thepsworld1");

}



