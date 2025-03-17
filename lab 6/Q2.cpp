#include <iostream>
using namespace std;

class MediaFile{    
    protected:
        int size;
        string path;

    public:
        MediaFile (int s , string p) : size(s) , path(p) { 
            cout << "PARENT CONTRUCTOR!!" << endl;
        }

        virtual void play(){
            cout << "START PLAYING!!" << endl;
        }

        virtual void stop(){
            cout << "STOP PLAYING!!" << endl;
        }

        virtual ~MediaFile(){
            cout << "PARENT DESTRUCTOR!!" << endl;
        }
};

class VisualMedia : virtual public MediaFile {   
    public:
        VisualMedia(int s, string p) : MediaFile(s,p) {
            cout << "CHILD 1 CONTRUCTOR!!" << endl;
        }

        ~VisualMedia(){
            cout << "CHILD 1 DESTRUCTOR!!" << endl;
        }
};

class AudioMedia :virtual public MediaFile {     
    public:
        AudioMedia(int s, string p) : MediaFile(s,p) {
            cout << "CHILD 2 CONTRUCTOR!!" << endl;
        }

        ~AudioMedia(){
            cout << "CHILD 2 DESTRUCTOR!!" << endl;
        }
};

class VedioFile : public VisualMedia , public AudioMedia {  
    public:
        VedioFile(int s, string p) : MediaFile(s, p), VisualMedia(s,p) , AudioMedia(s,p) {
            cout << "CHILD'S CHILD CONTRUCTOR!!" << endl;
        }

        void play() override {                 
            cout << "Playing video: " << path << endl;
        }
    
        void stop() override {                    
            cout << "Stopping video playback." << endl;
        }

        ~VedioFile(){
            cout << "CHILD'S CHILD DESTRUCTOR!!" << endl;
        }
};

int main() {
    MediaFile* media = new VedioFile(45, "mp4");    
    media->play();
    media->stop();
    delete media;


    return 0;
}