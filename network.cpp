#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
    string text_;
    
public:
    int i = 0;

    Message(){} 
    Message(string text) :text_(text){
        this->i++;
    }
    const string& get_text() {
        
        return this->text_;
    }
    
    int operator <(Message f)
		{
			if(this->i < f.i)
			return 1;
			else
			return 0;
		}
};


class MessageFactory {
public:
    MessageFactory() {}
    
    Message create_message(const string& text) {
        return Message(text);
        
    } 
};


class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        //sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    // MessageFactory message_factory;
    // Recipient recipient;
    // vector<Message> messages;
    // string text;
    // while (getline(cin, text)) {
    //     messages.push_back(message_factory.create_message(text));
    // }
    // Network::send_messages(messages, recipient);
    // recipient.print_messages();


    //MessageFactory m1;
   // m1.create_message("Hello");
    
    Message m2 = Message("hello");
    cout<<m2.i;
    Message m3 = Message("hello");
    cout<<m3.i;


}
