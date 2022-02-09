#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node{
private:
public:
    Node* next;
    bool bullet;                                        //탄의 유무
};

class Revolver{
private:
    Node* head;
public:    
    Node* cur;                                          //현재약실을 지목하는 변수
    int whatChamber;                                    //탄이 들어갈 약실 을 정할때 사용하는 변수     
                 
    void SetHead(Node* para)                            //access function
    {
        this->head = para;
    }

    Node* GetHead()                                     //access function
    {
        return head;
    }

    Revolver()                                          //constructor
    {
        head = NULL;
    }
    void CombineBullets()                               //약실생성 및 탄알장전
    {
        
        srand((unsigned int) time(NULL));               //seed값으로 현재시간 부여
        
        for(int i=0;i<6;i++)
        {
            Node* chamber = new Node;                   //약실 생성
            int curIndex = 1;
            chamber->next = NULL;

            chamber->bullet = false;                    //일단 탄은 넣지않음

            if(head == NULL)
            {
                //this->head = chamber;
                SetHead(chamber);
                
            }
            else
            {
                cur = GetHead();
                while(cur && i > curIndex)
                {
                    cur = cur->next;
                    curIndex++;
                }
                cur->next = chamber;
            }
            if(i == 5)                                          //마지막 약실 circular linked list
            {
                chamber->next = GetHead();
            }
        }

        whatChamber = rand() % 6;  
        //cout << "whatchamber:"<<whatchamber;                 //6개의 약실 중 랜덤한 하나의 약실
        cur = GetHead();
        for (int k = 0; k < 6; k++)
        {
            
            cur = cur->next;
            if (k == whatChamber)
            {
                cur->bullet = true;                             //탄알 1발장전
                break;
            }
        }
        
    }                              
    ~Revolver() ;                                               //destructor


    // void CombineBullets()                                 //1차 노드배열 코드 무시하십쇼
    // {
        
    //     // for(int i=0;i<5;i++)
    //     // {
    //     //     arr[i]->next = arr[i+1];
    //     //     arr[i]->bullet = false;         //탄을 넣지 않음
    //     // }
    //     // arr[5]->next = arr[0];              //circular linked list
    //     // arr[5]->bullet = false;             //마지막탄창도 비워줌

    //     // //head = arr[0];                      //처음엔 첫발이 head
    //     // arr[(rand() % 6)]->bullet = true;   //6발중 한발 랜덤으로 탄을 넣음
    //     // cur = arr[(rand() % 6)];            //cur을 6발중 랜덤으로 지정
    //     // Sethead(cur);                         //cur은 head를 지목
    // }

    bool shoot()
    {
        // cur = Gethead();
        if(cur->bullet == true)                 //현재 cur에 탄이 있다면
        {
            cout << "You Died...";
            return 0;
        }
        else                                    //탄이 없다면
        {
            cout << "You Survived!" << endl;
            cur = cur->next;                    //다음 탄창으로
            return 1;
        }
    }

    void rotate()
    {
        int russinalRoulette;
        russinalRoulette = rand() % 6;
        //cout<<"Russinal_Roulette"<<Russinal_Roulette <<endl;

        cur = GetHead();
        for(int k=0;k<russinalRoulette;k++)
        {
            cur = cur->next;       
        }
        SetHead(cur);         
        system("clear");                        //clear the screen
    }
};


int main()
{
    Revolver* gun = new Revolver;       //리볼버 생성
    gun->CombineBullets();              //약실 생성 및 탄알 장전
    gun->rotate();                      //rotate

    string cmdShoot = "shoot";
    string cmdRotate = "rotate";
    string input;


    cout << "Command list(shoot/rotate)" << endl;
    do
    {
        cout << "CMD>>";
        cin >> input;   
        if(input == cmdShoot)
        {
            if(gun->shoot() == 0)
            {
                return 0;
            }
        }
        else if(input == cmdRotate)
        {
            gun->rotate();
        }
        else                                //다른 commend 입력시
        {
            cout << "Wrong Command!" << endl;
        }
    } while(1);
    
    



    delete gun;
}