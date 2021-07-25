#include"Header.h"

int main() {


    Stacks ch(10);

    char* c = new char[30];
    cin.getline(c, 30);

    char* c1 = new char[strlen(c)];//для виводу в якому місці відбулась помилка

    char idol[6]{ '(','{','[',']','}',')' };//масив для перевірки збігу
   
    
    for (int i = 0; i < strlen(c); i++) {
        if (c[0] == idol[3] || c[0] == idol[4]|| c[0] == idol[5]){// якщо перший елемент ..)..}..]...виходимо з масиву 
             cout << "dont start with: "<<c[0];
             ch.Push(c[0]);
             break; }
                 else 
            if (c[i] == idol[0] || c[i] == idol[1] || c[i] == idol[2]) //якщо отриманий елемент ..(..{..[..незважаючи на попередній записуємо в стек   
                 ch.Push(c[i]);//добавляємо елемент в стек
                     else 
            if(((c[i] == idol[3]) && (ch.GetElement() != idol[2])) ||( (c[i] == idol[4]) && (ch.GetElement() != idol[1])) || ((c[i] == idol[5]) && (ch.GetElement() != idol[0])))    {
                     cout << "incorect input";//якщо для закриваючої дужки немає пари
                     break;}
                         else 
                if ((c[i] == idol[3])&&(ch.GetElement()== idol[2]))//якщо  для закриваючої дужки є пара    
                         ch.Pop();//видаляємо елемент з стеку 
                                else 
                    if ((c[i] == idol[4]) && (ch.GetElement() == idol[1]))
                                ch.Pop();
                                     else
                        if ((c[i] == idol[5]) && (ch.GetElement() == idol[0]))
                                     ch.Pop();
        c1[i]=c[i];
    }
    
    if (ch.IsEmpty()) //якщо стек пустий все зійшлось
        cout << "congratulations this " << c << " completed!!!";
    else
        cout << c1;
    
    delete[]c;
    delete[]c1;
  
	return 0;
}


