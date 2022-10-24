#include "cGato.h"

Gato::Gato()
{ 
  for (int i=0;i<9;i++)
    {
      Tile* t = new Tile();
      gato.push_back(t);
    }
  winner="none";
}

string Gato::display()
{
  string txt="";
  for (int i=1;i<10;i++)
    {
      txt+=gato.at(i-1)->getTile();
      if (i%3==0) txt+="\n";
      else txt+=" | ";
    }
  return txt;
}
void Gato::setP1(char _c) 
{
  p1=_c;
}
void Gato::setP2(char _c)
{
  p2=_c;
}
int Gato::getPos()
{
  return pos;
}
string Gato::getWinner()
{
  return winner;
}
vector<Tile*> Gato::getTiles()
{
  return gato;
}
void Gato::turn(int turn)
{
  cout<<"CURRENT BOARD: "<<endl<<display()<<endl;
  cout<<"Player "<<turn%2+1<<" set position (1-9): ";
  cin>>pos;
  while(gato.at(pos-1)->getTile()!='-')
  {
    cout<<"INVALID INPUT"<<endl<<"Player "<<turn%2+1<<" set position (1-9): ";
    cin>>pos;
  }
  if (turn%2==0)
  {
    gato.at(pos-1)->setTile(p1);
  }
  else
  {
    gato.at(pos-1)->setTile(p2);
  }
  turn++;
  if((gato.at(0)->getTile()==gato.at(1)->getTile()&&gato.at(1)->getTile()==gato.at(2)->getTile())&&gato.at(0)->getTile()!='-'||(gato.at(0)->getTile()==gato.at(3)->getTile()&&gato.at(3)->getTile()==gato.at(6)->getTile())&&gato.at(0)->getTile()!='-'||(gato.at(0)->getTile()==gato.at(4)->getTile()&&gato.at(4)->getTile()==gato.at(8)->getTile())&&gato.at(0)->getTile()!='-'||(gato.at(1)->getTile()==gato.at(4)->getTile()&&gato.at(4)->getTile()==gato.at(7)->getTile())&&gato.at(1)->getTile()!='-'||(gato.at(2)->getTile()==gato.at(5)->getTile()&&gato.at(5)->getTile()==gato.at(8)->getTile())&&gato.at(2)->getTile()!='-'||(gato.at(2)->getTile()==gato.at(4)->getTile()&&gato.at(4)->getTile()==gato.at(6)->getTile())&&gato.at(2)->getTile()!='-'||(gato.at(4)->getTile()==gato.at(3)->getTile()&&gato.at(3)->getTile()==gato.at(5)->getTile())&&gato.at(3)->getTile()!='-'||(gato.at(6)->getTile()==gato.at(7)->getTile()&&gato.at(8)->getTile()==gato.at(6)->getTile())&&gato.at(6)->getTile()!='-')
  {
    winner=gato.at(pos-1)->getTile();
    cout<<"THE WINNER OF THIS GAME IS PLAYER "<<winner<<endl;
  } 
  for (int i=0;i<9;i++)
  {
    if(gato.at(i)->getTile()=='-') break;          
    if (i==8)
    {
      winner="TIE";
      cout<<"THIS GAME ENDED IN A TIE"<<endl;
    }
  }  
}