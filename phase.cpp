#include <iostream>
#include <ctime>
#include <unistd.h>

void welcome(std::string username)
{   
    for (char c : "Welcome ") {
        std::cout << c;
        usleep(2000);}
    std::cout << username <<" !\n";
    system("pause");
    system("cls");
}

void login(std::string user[], int len2, std::string pass[])
{
    std::string username, password;
    //std::cout << "Enter username: \n";
    for (char c : "Enter username:\n") {
        std::cout << c;
        usleep(2000);}
    std::cin >> username;
    //std::cout << "Enter password: \n";
    for (char c : "Enter password:\n") {
        std::cout << c;
        usleep(2000);}
    std::cin >> password;

    for (int i = 0; i < len2; i++)
    {

        if (username == user[i])
        {
            if (password == pass[i])
            {
                welcome(username);
                return;
            }
            else if (password != pass[i])
            {
                do
                {
                    for (char c : "The password was incorrect!\n;//Enter password: \n") {
                        std::cout << c;
                        usleep(2000);}
                    //std::cout << "The password was incorrect! \n;//Enter password: \n";
                    std::cin >> password;

                } while (password != pass[i]);
                welcome(username);
                return;
            }
        }
    }
    for (char c : "Either the username or the password was not found! \n") {
        std::cout << c;
        usleep(2000);}
    //std::cout << "Either the username or the password was not found! \n";
    system("pause");
    system("cls");
}

bool checkPassA(std::string password)
{
    for (char c : password)
    {
        if (isalpha(c) != 0)
        {
            return true;
        }
    }
    return false;
}
bool checkPassD(std::string password)
{

    for (char c : password)
    {
        if (isdigit(c) != 0)
        {
            return true;
        }
    }
    return false;
}
void signup(std::string user[], int& len2, std::string pass[]); // declare

void confirmation(std::string passwordConfirmation, std::string user[], int& len2, std::string pass[], std::string usernameconfirmation)
{
    int number1;
    int number2;
    int captcha;
    int exit = 0;
    std::string password;
    for (char c : "Confirm your password please : ") {
        std::cout << c;
        usleep(2000);}
    //std::cout << "Confirm your password please : ";
    std::cin >> password;

    while (password != passwordConfirmation)
    {
        for (char c : "The given password is not matching, try again: ") {
            std::cout << c;
            usleep(2000);}
        //std::cout << "The given password is not matching, try again: ";
        std::cin >> password;
        if (exit == 2)
        {
            system("cls");
            for (char c : "You have tried too much!\nyou will be returned to the main menu!\n") {
                std::cout << c;
                usleep(2000);}
            //std::cout << "You have tried too much \nyou will be returned to the main menu!\n";
            system("pause");
            system("cls");
            return;
        }
        exit++;
    }
    srand(static_cast<unsigned>(time(0)));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    //bool human = false;
    int sum = num1 + num2;
    std::cout << "Whats the sum of these two numbers? " << num1 << " and " << num2 << " : ";
    std::cin >> captcha;
    
    if (captcha ==sum)
    {
        pass[len2] = passwordConfirmation;
        user[len2] = usernameconfirmation;
        len2++;
        //std::cout << len2 << std::endl;
        for (char c : "How wonderfull mate!\n") {
                std::cout << c;
                usleep(2000);}
        //std::cout << "How wonderfull mate!\n";
        system("pause");
        //return;
    }
    else
    {
        std::cout << "YOU ARE A ROBOT KASAGAM !\nYou will be returned to main menu!\n";
        system("pause");
        system("cls");
        return;
    }
}

void signup(std::string user[], int& len2, std::string pass[])
{

    std::string username, password;
    //std::cout << "Enter username: \n";
    for (char c : "Enter username:\n") {
        std::cout << c;
        usleep(2000);
    }
    //userInput();
    std::cin >> username;
    //std::cout << "Enter password: \n";
    for (char c : "Enter password:\n") {
        std::cout << c;
        usleep(2000);
    }
    //passInput();
    std::cin >> password;

    while (password.length() < 8 || password.length() > 20 || checkPassA(password) == false || checkPassD(password) == false)
    {
        if (password.length() < 8 || password.length() > 20)
        {
            std::cout << "Password must be between 8 to 20 characters, Enter again: ";
        }
        else if (checkPassA(password) == false || checkPassD(password) == false)
        {
            std::cout << "The password must be the combination of digits and alphabets: ";
        }

        std::cin >> password;
    }

    for (int i = 0; i < len2; i++)
    {
        while (user[i] == username)
        {
            std::cout << "The username given is not available,try again:\n";
            std::cin >> username;
        }
    }
    confirmation(password, user, len2, pass, username);
    // system("pause");
    system("cls");
}

int main()
{
    std::string input;
    std::string user[100];
    std::string pass[100];
    int len2 = 0;
    do
    {

        system("cls");
        std::cout << "Welcome to the program\nPlease select a choice!\n";
        std::cout << "1)signup\n2)login\n3)exit\n";
        std::cin >> input;
        system("cls");
        while (input != "1" && input != "2" && input != "3")
        {
            std::cout << "Your choice is not among the options.\nPlease choose a number between 1,2,3 !\n";
            std::cout << "1)signup\n2)login\n3)exit\n";
            std::cin >> input;
            system("cls");
        }

        if (input == "1")
        {
            system("cls");
            signup(user, len2, pass);
        }
        else if (input == "2")
        {   
            if(len2==0){
                system("cls");
                std::cout << "You have not created an account !\nYou will be returned to the menu!\n";
                system("pause");
                system("cls");
            }    
            system("cls");
            if (len2!=0)
            {
                login(user, len2, pass);
            }
        }
    } while (input != "3");
    return 0;
}
