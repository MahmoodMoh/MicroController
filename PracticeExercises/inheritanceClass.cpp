#include <iostream>
using namespace std;
#include <list>

// Base Class
class YouTubeChannel {

    private:
    string Name;
    
    int SubscribersCount;
    list<string> PublishedVideoTitles;

    protected:
    string OwnerName;
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

// Inheritance

class CookingYouTubeChannel: public YouTubeChannel {

    public:
    CookingYouTubeChannel(string name, string OwnerName): YouTubeChannel(name, OwnerName) {

    }
    void Practice(){
        cout <<OwnerName <<" is practicing cooking, learning new recipes, experimenting with spices ..." << endl;

    }

};
int main(){

    CookingYouTubeChannel cookingYchannel("Khan's Kitchen", "Khan");
    CookingYouTubeChannel cookingYchannel2("John's Taste", "John");
    /*cookingYchannel.PublishedVideo("Apple pie");
    cookingYchannel.PublishedVideo("Qabuli palaw");
    cookingYchannel.Subscribe();
    cookingYchannel.Subscribe();
    cookingYchannel.Subscribe();
    cookingYchannel.GetInfo();*/
    cookingYchannel.Practice();
    cookingYchannel2.Practice();
}