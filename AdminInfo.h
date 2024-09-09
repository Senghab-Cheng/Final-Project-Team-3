#pragma once 

#include <iostream>
using namespace std;

class Admin{
    private :
        string username = "ABC";
        string email = "abc123@gmail.com";
        string password = "12345";
        string bio = "No idea";
        string tel = "0123456789";
        string telegram = "ABC";
        string gitHub = "abc123";

    public :
        string getUsername() {
            return username;
        }
        string getEmail() {
            return email;
        }
        string getPassword() {
            return password;
        }
        string getBio() {
            return bio;
        }
        string getTel() {
            return tel;
        }
        string getTelegram() {
            return telegram;
        }
        string getGitHub() {
            return gitHub;
        }
};