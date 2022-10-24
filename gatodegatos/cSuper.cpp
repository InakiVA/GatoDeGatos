#include "cSuper.h"

Super::Super()
{
  for (int i=0;i<9;i++)
  {
    Gato* g = new Gato();
    vgato.push_back(g);
  }
  end=false;
}
string Super::display()
{
  string txt="";
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<2) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=0;i<3;i++)
  {
    for (int j=3;j<6;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<5) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=0;i<3;i++)
  {
    for (int j=6;j<9;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<8) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n\n";

  for (int i=3;i<6;i++)
  {
    for (int j=0;j<3;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<2) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=3;i<6;i++)
  {
    for (int j=3;j<6;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<5) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=3;i<6;i++)
  {
    for (int j=6;j<9;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<8) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n\n";

  for (int i=6;i<9;i++)
  {
    for (int j=0;j<3;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<2) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=6;i<9;i++)
  {
    for (int j=3;j<6;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<5) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  for (int i=6;i<9;i++)
  {
    for (int j=6;j<9;j++)
    {
      txt+=vgato.at(i)->getTiles().at(j)->getTile();
      if (j<8) txt+=" | ";
      else txt+="\t\t";
    }    
  }
  txt+="\n";
  
  return txt;
}
void Super::start()
{
  string txt="";
  int temp, turn=0;
  cout<<"Set char for player 1: ";
  cin>>p1;
  cout<<"Set char for player 2: ";
  cin>>p2;
  for (int i=0;i<9;i++)
  {
    vgato.at(i)->setP1(p1);
    vgato.at(i)->setP2(p2);
  }
  for (int i=1;i<10;i++)
  {
    txt+=to_string(i);
    if (i%3==0) txt+="\n";
    else txt+=" | ";
  }
  cout<<endl<<txt<<endl<<display()<<endl;
  cout<<"Set initial position: ";
  cin>>pos;
  while (end==false)
  {
    while (vgato.at(pos-1)->getWinner()!="none")
    {
      cout<<endl<<"Choose game to play in: ";
      cin>>pos;
    }
    vgato.at(pos-1)->turn(turn);
    pos=vgato.at(pos-1)->getPos(); 
    cout<<endl<<display()<<endl;
    turn++;
    if((vgato.at(3)->getWinner()==vgato.at(4)->getWinner()&&vgato.at(4)->getWinner()==vgato.at(5)->getWinner()&&vgato.at(4)->getWinner()!="none")||      (vgato.at(1)->getWinner()==vgato.at(4)->getWinner()&&vgato.at(4)->getWinner()==vgato.at(7)->getWinner()&&vgato.at(4)->getWinner()!="none")||      (vgato.at(0)->getWinner()==vgato.at(4)->getWinner()&&vgato.at(4)->getWinner()==vgato.at(8)->getWinner()&&vgato.at(4)->getWinner()!="none")||      (vgato.at(2)->getWinner()==vgato.at(4)->getWinner()&&vgato.at(4)->getWinner()==vgato.at(6)->getWinner()&&vgato.at(4)->getWinner()!="none"))
    {
      cout<<"THE FINAL WINNER IS PLAYER "<<vgato.at(4)->getWinner()<<endl;
      end=true;
    }
    else if((vgato.at(0)->getWinner()==vgato.at(1)->getWinner()&&vgato.at(1)->getWinner()==vgato.at(2)->getWinner()&&vgato.at(0)->getWinner()!="none")||      (vgato.at(0)->getWinner()==vgato.at(3)->getWinner()&&vgato.at(3)->getWinner()==vgato.at(6)->getWinner()&&vgato.at(0)->getWinner()!="none"))
    {
      cout<<"THE FINAL WINNER IS PLAYER "<<vgato.at(0)->getWinner()<<endl;
      end=true;
    }
    else if((vgato.at(2)->getWinner()==vgato.at(5)->getWinner()&&vgato.at(5)->getWinner()==vgato.at(8)->getWinner()&&vgato.at(8)->getWinner()!="none")||      (vgato.at(6)->getWinner()==vgato.at(7)->getWinner()&&vgato.at(7)->getWinner()==vgato.at(8)->getWinner()&&vgato.at(8)->getWinner()!="none"))
    {
      cout<<"THE FINAL WINNER IS PLAYER "<<vgato.at(8)->getWinner()<<endl;
      end=true;
    }
    else if (end==false)
    {
      end=true;
      for(int i=0;i<display().size();i++)
      {
        if (display().at(i)=='-')
        {
          end=false;
          break;
        }
      }
      if (end==true) cout<<"TIE"<<endl;
    }    
  }
}