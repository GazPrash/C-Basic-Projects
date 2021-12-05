#include<iostream>
#include<vector>


using namespace std;

class Validator{
    public:
        string card_no;
        vector<int> convertor(string);
        int analyzer(vector<int>);

};

vector<int> Validator :: convertor(string cred){
    vector<int> new_vec;

    for (int i = 0; i < cred.size(); i++)
    {
        new_vec.push_back(int(cred[i]));
    }
    
    return new_vec;


}

int Validator :: analyzer(vector<int> cred_arr){
    // vector<int> temp_vec;
    int sum;

    for (int i = cred_arr.size()-1; i > 0; i = i-2)
    {
        cred_arr[i] = (cred_arr[i] * 2);
        if (cred_arr[i] > 9){
            string new_dig = to_string(cred_arr[i]);
            int a = int(new_dig[0]);
            int b = (new_dig[1]);
            sum += (a+b);
        }

        else{
            sum += cred_arr[i];

        }


    }

    if (sum % 10 == 0){
        return 1;

    }

    return 0;
    


}


int main(){
    string cred_num;
    cout<<"Enter Your Credit Card No: ";
    cin>>cred_num;

    Validator validate1;

    vector<int> cred_array = validate1.convertor(cred_num);
    if (validate1.analyzer(cred_array)){
        cout<<"Card Verified!";
    }

    else{
        cout<<"Card Not Verified...";

    }

    return 0;
    



}



