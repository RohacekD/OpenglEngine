#include "test/Test.h"
#include "Fps.h"
#include "Shapes/Shapes.h"

Cube* Test::kostka;
int unsigned Test::Time;
int unsigned Test::Times;
int Test::counter;
SDL_Event Test::event;
int* Test::val;

Test::Test()
{
    kostka = new Cube(0,0,0,1);
        Cube::Cache->SetForce(1,0,0);
    Cube::End();
    event.type=SDL_USEREVENT;
    counter = 0;
    Time = SDL_GetTicks();
    Times = 0;
    val=new int[5];
    val[0]=30;
    val[1]=40;
    val[2]=130;
    val[3]=60;
    val[4]=5;
    NewTest();
}

Test::~Test(){}

void Test::Cycle(){
    if(Time+1000>SDL_GetTicks()){
    }
    else NewTest();
}

void Test::NewTest(){
    std::cout<<"Test "<<Times<<" y: "<<kostka->Position[X]<<std::endl;
    if(Times!=5){
        kostka->Position.SetVertex(0,0,0);
        Fps::Instance()->SetFps(val[Times]);
        Times++;
        Time=SDL_GetTicks();
    }
    else SDL_PushEvent(&event);

}
