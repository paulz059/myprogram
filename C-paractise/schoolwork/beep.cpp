/**#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <mmstsrem.h>
suing namespace std;

int sound(int frequency,int duration){
    Beep(frequency,duration);
    return 0;
}

int main() {
    int start = 262;
    int end = 523;
    dur = 1000;
    for(int i = 0 ; i <=8; i++){
        sound(start+i*30,1000);
    }// 发出523Hz的蜂鸣声，持续时间为500毫秒
    return 0;
}**/
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <mmsystem.h>
#include <vector>
using namespace std;
#define QUARTER_SPEED 200
#define FREQ_CNT 8 

class Note {
public:
    std::string name;
    int duration;

    Note(const std::string& n, int d) : name(n), duration(d) {}
};

#define qdo 262 
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865


/* int note_to_frequency(const string& note) {
    if (note == "C4") return C4;
    if (note == "D4") return D4;
    if (note == "E4") return E4;
    if (note == "F4") return F4;
    if (note == "G4") return G4;
    if (note == "A4") return A4;
    if (note == "B4") return B4;
    if (note == "C5") return C5;
    if (note == "D5") return D5;
    if (note == "E5") return E5;
    if (note == "F5") return F5;
    if (note == "G5") return G5;
    if (note == "A5") return A5;
    if (note == "B5") return B5;
    return 0;
} */


int main()
{
int pai=400,ban=200;
int ting=128;

int melody[] = {la,si,0,do1,si,0,do1,0,mi1,0
                ,si,0,mi,mi,la,so,0,la,0,
                do1,0,so,0,pai,mi,0,mi,0,
                fa,mi,0,fa,do1,1,
                mi,0,0,do1,0,do1,0,do1,
                };

float noteDurations[] = {1,1,1,3,1,1,2,1,2,1,
                        6,1,1,1,3,1,1,2,1,
                        2,1,4,1,1,1,0.5,1,0.5
                        ,3,1,1,1,3,1
                        ,4,1,1,1,0.25,1,0.5,0.25,

                        };

int tempo = 200;

    for (int i = 0; i < sizeof(melody) / sizeof(*melody); i++) {
        if (melody[i] == 0) {
            Sleep(noteDurations[i] * tempo);
        } else {
            Beep(melody[i], noteDurations[i] * tempo);
        }
    }

cout << "step 2";   
Sleep(1000);

Beep(la,ban);
Beep(si,ban);
Sleep(ting);

Beep(do1,pai+ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);

Beep(si,3*pai);
Sleep(ting);
Beep(mi,ban);
Beep(mi,ban);

Beep(la,ban+pai);
Beep(so,ban);
Sleep(ting);
Beep(la,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(so,2*pai);
Sleep(ting);
Sleep(pai);
Beep(mi,ban);
Sleep(ting/2);
Beep(mi,ban);
Sleep(ting/2);

Beep(fa,pai+ban);
Beep(mi,ban);
Sleep(ting);
Beep(fa,ban);
Beep(do1,ban+pai);
Sleep(ting);

Beep(mi,2*pai);
Sleep(ting);
Sleep(ban);
Beep(do1,ban);
Sleep(ting/2);
Beep(do1,ban);
Sleep(ting/2);
Beep(do1,ban);
Sleep(ting/2);

Beep(si,ban+pai);
Beep(sfa,ban);
Sleep(ting);
Beep(sfa,pai);
Beep(si,pai);
Sleep(ting);

Beep(si,2*pai);
Sleep(ting);
Sleep(pai);
Beep(la,ban);
Beep(si,ban);
Sleep(ting);

Beep(do1,pai+ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);

Beep(si,2*pai);
Sleep(ting);
Sleep(pai);
Beep(mi,ban);
Sleep(20);
Beep(mi,ban);
Sleep(ting);

Beep(la,pai+ban);
Beep(so,ban);
Sleep(ting);
Beep(la,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(so,3*pai);
Sleep(ting+ban);
Beep(mi,ban);
Sleep(ting/2);

Beep(fa,pai);
Sleep(ting);
Beep(do1,ban);
Beep(si,ban);
Sleep(20);
Beep(si,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(re1,ban);
Sleep(20);
Beep(re1,ban);
Sleep(20);
Beep(mi1,ban);
Sleep(ting/2);
Beep(do1,pai);
Sleep(ting+pai);

Beep(do1,pai);
Beep(si,ban);
Sleep(ting);
Beep(la,ban);
Sleep(20);
Beep(la,ban);
Sleep(ting);
Beep(si,pai);
Sleep(ting);
Beep(sso,pai);
Sleep(ting);

Beep(sso,2*pai);
Sleep(ting+pai);
Beep(do1,ban);
Beep(re1,ban);
Sleep(ting);

Beep(mi1,pai+ban);
Beep(re1,ban);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);
Beep(fa1,pai);
Sleep(ting);

Beep(re1,2*pai);
Sleep(pai+ting);
Beep(so,ban);
Sleep(20);
Beep(so,ban);
Sleep(ting);

Beep(do1,ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);

Beep(mi1,2*pai);
Sleep(ting+2*pai);

Beep(la,ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(si,pai);
Sleep(ting);
Beep(re1,ban);
Sleep(20);
Beep(re1,ban);
Sleep(ting);

Beep(do1,pai+ban);
Beep(so,ban);
Sleep(20);
Beep(so,pai);
Sleep(pai+ting);

Beep(fa1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);
Beep(re1,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(mi1,4*pai);

Beep(mi1,pai*2);
Sleep(pai+ting);
Beep(mi1,pai);
Sleep(ting);

Beep(la1,2*pai);
Sleep(ting);
Beep(so1,pai);
Sleep(ting);
Beep(so1,pai);
Sleep(ting);

Beep(mi1,ban);
Sleep(ting/2);
Beep(re1,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting+ban);
Beep(do1,ban);
Sleep(ting);

Beep(re1,pai);
Sleep(ting);
Beep(do1,ban);
Beep(re1,ban);
Sleep(20);
Beep(re1,ban);
Sleep(ting);
Beep(so1,pai);
Sleep(ting);

Beep(mi1,2*pai);
Sleep(ting+pai);
Beep(mi,pai);
Sleep(ting);

Beep(la1,2*pai);
Sleep(ting);
Beep(so1,2*pai);
Sleep(ting);

Beep(mi1,ban);
Beep(re1,ban);
Sleep(ting);
Beep(do1,2*pai);
Sleep(ting+ban);
Beep(do1,ban);
Sleep(ting);

Beep(re1,pai);
Sleep(ting);
Beep(do1,ban);
Beep(re1,ban);
Sleep(20);
Beep(re1,ban);
Sleep(ting);
Beep(si,pai);
Sleep(ting);

Beep(la,2*pai);
Sleep(ting);
Beep(la,ban);
Beep(si,ban);

Beep(do1,pai+ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);

Beep(si,3*pai);
Sleep(ting);
Beep(mi,ban);
Beep(mi,ban);

Beep(la,ban+pai);
Beep(so,ban);
Sleep(ting);
Beep(la,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(so,2*pai);
Sleep(ting);
Sleep(pai);
Beep(mi,ban);
Sleep(ting/2);
Beep(mi,ban);
Sleep(ting/2);

Beep(fa,pai+ban);
Beep(mi,ban);
Sleep(ting);
Beep(fa,ban);
Beep(do1,ban+pai);
Sleep(ting);

Beep(mi,2*pai);
Sleep(ting);
Sleep(ban);
Beep(do1,ban);
Sleep(ting/2);
Beep(do1,ban);
Sleep(ting/2);
Beep(do1,ban);
Sleep(ting/2);

Beep(si,ban+pai);
Beep(sfa,ban);
Sleep(ting);
Beep(sfa,pai);
Beep(si,pai);
Sleep(ting);

Beep(si,2*pai);
Sleep(ting);
Sleep(pai);
Beep(la,ban);
Beep(si,ban);
Sleep(ting);

Beep(do1,pai+ban);
Beep(si,ban);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);
Beep(mi1,pai);
Sleep(ting);

Beep(si,2*pai);
Sleep(ting);
Sleep(pai);
Beep(mi,ban);
Sleep(20);
Beep(mi,ban);
Sleep(ting);

Beep(la,pai+ban);
Beep(so,ban);
Sleep(ting);
Beep(la,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(so,3*pai);
Sleep(ting+ban);
Beep(mi,ban);
Sleep(ting/2);

Beep(fa,pai);
Sleep(ting);
Beep(do1,ban);
Beep(si,ban);
Sleep(20);
Beep(si,pai);
Sleep(ting);
Beep(do1,pai);
Sleep(ting);

Beep(re1,ban);
Sleep(20);
Beep(re1,ban);
Sleep(20);
Beep(mi1,ban);
Sleep(ting/2);
Beep(do1,pai);
Sleep(ting+pai);

Beep(la,4*pai);

Sleep(1000);

main();

}