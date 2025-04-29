/*
Polymorphism:
             Describes the ability of an object to have multiple forms. That means that you can have two or more objectrs,
             that inherits from the base class, those objects can have the same name but different implementation and different
             behaviour

*/
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
    int ContentQuality;

    // Constructor
    public:
    YouTubeChannel(string name, string owner) {
    Name = name;
    OwnerName = owner;
    SubscribersCount = 0;
    ContentQuality = 0;
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
    void CheckAnalytics() {
        if(ContentQuality < 5)
        cout<< Name <<" has bad quality content. "<< endl;
        else
        cout<< Name <<" has a good quality content. " << endl;
    }
};

// Inheritance

class CookingYouTubeChannel: public YouTubeChannel {


    public:
    CookingYouTubeChannel(string name, string OwnerName): YouTubeChannel(name, OwnerName) {

    }
    void Practice(){
        cout <<OwnerName <<" is practicing cooking, learning new recipes, experimenting with spices ..." << endl;
        ContentQuality++;

    }

};
class SingersYouTubeChannel : public YouTubeChannel {
    public:
    SingersYouTubeChannel(string name, string OwnerName): YouTubeChannel(name, OwnerName) {

    }
    void Practice() {
        cout << OwnerName <<" is taking singing classes, learning new songs, learning how to dance..." <<endl;
        ContentQuality++;

    }
};


int main(){
    CookingYouTubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    SingersYouTubeChannel singersYtChannel("John's voice", "John");

    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();

    YouTubeChannel* yt1 = &cookingYtChannel;
    YouTubeChannel* yt2 = &singersYtChannel;

    yt1->CheckAnalytics();  // -> is used when invoking a pointer
    yt2->CheckAnalytics();



    return 0;
}