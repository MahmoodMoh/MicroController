#include <iostream>
#include <list>
using namespace std;
// Note: Members of the class are private by default, and members of a structure are public by default

struct YouTubeChannel{
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount){
        Name = name;
        SubscribersCount = subscribersCount;

    }
};

ostream& operator<<(ostream& COUT, YouTubeChannel& ytchannel) {
    COUT << "Name: " << ytchannel.Name << endl;
    COUT << "SubscribersCount: " << ytchannel.SubscribersCount << endl;
    return COUT;

}

struct MyCollection {
    list<YouTubeChannel>myChannels;

};
int main(){
YouTubeChannel yt1 = YouTubeChannel("Code Beauty", 380000);
YouTubeChannel yt2 = YouTubeChannel("My second channel", 40000);
cout << yt1 << yt2;

return 0;

}