#include <iostream>
using namespace std;

int tabs = 0; //Для создания отступов
//Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в фукцию print

// //Структура ветки
// typedef struct s_node
// {
// 	char Data; //Поле данных
// 	struct s_node *LeftNode; //УКАЗАТЕЛИ на соседние веточки
// 	struct s_node *RightNode;
// 	struct s_node *Parrent;
// }Node;


//Функция внесения данных
void Add(char aData, Node *&aNode)
{
 //Если ветки не существует
 if (!aNode)
 { //создадим ее и зададим в нее данные
 aNode = new Node;
 aNode->Data = aData;
 aNode->LeftNode = 0;
 aNode->RightNode = 0;
 return;
 }
 else //Иначе сверим вносимое
 if (aNode->Data>aData)
 { //Если оно меньше того, что в этой ветке - добавим влево
 Add(aData, aNode->LeftNode);
 }
 else
 { //Иначе в ветку справа
 Add(aData, aNode->RightNode);
 };
}

//Функция вывода дерева
void print(Node *aNode)
{
 if (!aNode) return; //Если ветки не существует - выходим. Выводить нечего
 tabs++; //Иначе увеличим счетчик рекурсивно вызванных процедур
 //Который будет считать нам отступы для красивого вывода

 print(aNode->LeftNode); //Выведем ветку и ее подветки слева

 for (int i = 0; i<tabs; i++) cout << "	"; //Потом отступы
 cout << aNode->Data << " " << endl; //Данные этой ветки


 print(aNode->RightNode);//И ветки, что справа

 tabs--; //После уменьшим кол-во отступов
 return;
}

void FreeTree(Node *aNode)
{
 if (!aNode) return;
 FreeTree(aNode->LeftNode);
 FreeTree(aNode->RightNode);
 delete aNode;
 return;
}


int main()
{
 Node *Root = 0;
 char s[] = "84527819";

 for (int i = 0; s[i]; i++)
 {
 Add(s[i], Root);
 }

 print(Root);
 FreeTree(Root);

//  cin.get();
 return 0;
}
