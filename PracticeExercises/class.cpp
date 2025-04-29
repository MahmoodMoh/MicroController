#include <iostream>
using namespace std;
#include <list>

class YouTubeChannel {

    private:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

    public:
    YouTubeChannel(string name, string owner) {
    Name = name;
    OwnerName = owner;
    SubscribersCount = 0;
    }

    void GetInfo() {
    cout <<"Name: " << Name << endl;
    cout <<"Ownername: " << OwnerName << endl;
    cout << "SubscribersCount: " <<SubscribersCount << endl;
    cout <<"Videos: " << endl;
    for (string videoTitle : PublishedVideoTitles) {
        cout << videoTitle << endl;

    }}
    
    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if(SubscribersCount > 0)
        SubscribersCount--;
    }
    void PublishedVideo(string titles){

        PublishedVideoTitles.push_back(titles);
    }
    
};

int main(){
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishedVideo("Hello World! ");
    ytChannel.PublishedVideo("C++ for beginners");
    ytChannel.PublishedVideo("Earth");
    ytChannel.Subscribe();
    ytChannel.Subscribe(); 
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();

    cout <<endl<<endl;
    YouTubeChannel ytChannel2("New life", "MM");
    ytChannel2.PublishedVideo("Explorer");
    
    ytChannel2.GetInfo();
    
    

    return 0;
}