

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct node {
  double id;
  string name;
  double gpa;
  node *nxt;
};

node createNode1();
void createNode();
void printList();
int checkStudentId(int);
void enterNodeInfo(struct node *);
bool noShell = true;
bool emptyShell = true;
struct node *start;
struct node *current;
struct node *previous;
struct node *temp;
double deleteid;


void emptyness(){
  if (start == NULL)
    emptyShell = true;
    else
     emptyShell = false;
}


void createNode() {
  if (noShell) {
    struct node *start = NULL;
    struct node *current = NULL;
    //struct node *previous = NULL;
    struct node *temp = NULL;
    current = start;
    temp = current->nxt;
    noShell = false;
    cout << "Linked list is created." << endl;
  } else {
    cout << "The linked list has already been created." << endl;
  }
}

// struct node *start, struct node *current, struct node *prev
void addNode() {
emptyness();
  if (noShell) {
    cout << "Please create a linked list first." << endl;
  } else {
    node *s;
    s = new node;

    enterNodeInfo(s);

    double studentId = s->id;
    current = start;
    while (current->id < studentId && current != NULL) {
      previous = current;
      current = current->nxt;
    }
    if (current == start) {
      s->nxt = start;
      start = s;
    } else {
      previous->nxt = s;
      s->nxt = current;
    }
    cout << "A new list is added." << endl;
    cout << "Start pointer points : " << start->id << endl;
    //emptyShell = false;
  }
}

void enterNodeInfo(struct node *s) {
  int studentId;
  string realName;
  cout << "Please enter an Id: ";
  cin >> studentId;
  temp = start;
  studentId = checkStudentId(studentId);
  s->id = studentId;
  cin.ignore();
  cout << "Please enter the person's name: ";
  getline(cin, realName);
  s->name = realName;
  cout << "Please enter the person's GPA: ";
  cin >> s->gpa;
  s->nxt = NULL;
}

int checkStudentId(int studentId) {
  temp = start;
  while (temp != NULL) {
    if (temp->id == studentId) {
      cout << "You have already used this ID. Please enter a different ID."
           << endl;
      cin >> studentId;
      //cin.ignore();
    } else {
      temp = temp->nxt;
    }
  }
  //cin.ignore();
  return studentId;
}
void matchingID ()
    {
       while (current-> id != deleteid)
      {
        current = current -> nxt;
         if (current == NULL)
         {
         cout << "No matching ID." << endl;
         current = temp;
           break;
          }
        }
    }
  void deletefirstnode()
{

    temp= start;
    temp = temp->nxt;
    start = temp;
    delete current;
    cout << "Node successfully deleted"; 


}
void deletelastnode()
{
  previous = start;
        while (previous->nxt != current)
          {
            previous = previous -> nxt;
          }
        previous -> nxt = NULL ;
        delete current;
      cout << "Node successfully deleted";
}
void deletemiddlenode()
{
        previous = start;
        while (previous->nxt != current)
          {
            previous = previous -> nxt;
          }
        temp =start;
        while (current->nxt != temp)
          {
            temp = temp->nxt;
          }
        previous -> nxt = temp;
        delete current;
        cout << "Node successfully deleted";
  }
void deleteNode()
{
  emptyness();
  if (noShell) {
    cout << "Please create a linked list first." << endl;
    }
  else if (emptyShell) {
    cout << "Linked list is empty.No nodes can be deleted." << endl;
    }
  else{  //node exist

    cout << "Please enter the ID of the node that you want to delete: ";
    cin >> deleteid;
    current = start;
    matchingID (); 

     if (current == start)
     {
       deletefirstnode();
     }

    else if (current->nxt == NULL)
    {
      deletelastnode();
    }

      else 
      {
        deletemiddlenode();
      }

    }

}

void searchNode() {
  emptyness();
if (noShell) {
    cout << "Please create a linked list first." << endl;
  } else if (emptyShell) {
    cout << "Linked list is empty." << endl;
  } else {
    double searchID;
    cout << "Please enter an Id that you are looking for : ";
    cin >> searchID;
    temp = start;
  while (temp != NULL) {
    if (temp->id == searchID) {
      cout << "ID: " << setw(5) << temp->id << "  |  ";
      cout << "GPA: " << setw(4) << temp->gpa << "  |  ";
      cout << "Name: " << temp->name << endl;
      break;
    }
    else {
      temp = temp->nxt;
      if (temp == NULL)
        cout << "No Matching ID Exists\n";
        }
    }
  }
}

void displayNode() {
emptyness();
  if (noShell) {
    cout << "Please create a linked list first." << endl;
  } else if (emptyShell) {
    cout << "Linked list is empty." << endl;
  } else {
    node *newDisplay = start;
    while (newDisplay) {
      cout << "ID: " << setw(5) << newDisplay->id << "  |  ";
      cout << "GPA: " << setw(4) << newDisplay->gpa << "  |  ";
      cout << "Name: " << newDisplay->name << endl;
      newDisplay = newDisplay->nxt;
    }
  }
}

void modifynode()
{
   double modifyid;
   emptyness();
   if (noShell) {
    cout << "Please create a linked list first." << endl;
   } 
  else if (emptyShell) {
    cout << "Linked list is empty." << endl;
  }
  else{
    cout << "Please enter the ID of the node that you would like to modify:";
  cin  >> modifyid;
  temp = start;
  while (temp != NULL) {
    if (temp->id == modifyid ) 
    {
      cout << "You are allowed to modify only the GPA and the name."<< endl;
      cout << "ID: " << temp->id << "  |  ";
      cout << "New GPA: ";
      cin  >> temp->gpa;
      cout << "  |  ";
      cout << "New Name: ";
      cin  >> temp->name;
      cout << "Node successfulyy modified.";

      cout << endl;
      break;
    }
    else {
      temp = temp->nxt;
      if (temp == NULL)
        cout << "No Matching ID Exists\n";
    }

  }
  }

} 

void purgeNode(){
  emptyness();
  if (noShell) {
    cout << "Please create a linked list first." << endl;
  } else if (emptyShell) {
    cout << "Linked list is empty." << endl;
  } else {
     current = start;
    if (start->nxt == NULL){
      delete current;
      start = NULL;
      cout << "List is deleted\n";
    }
    else {
    while (start != NULL) {
      start = current -> nxt;
      delete current;
      current = start;
      cout << "List is deleted\n";
      }
    }
    cout <<"The Node is successfully purged\n";
    }
  }

void executeSelection(int &selection) {
  switch (selection) {
  case 1:
    createNode();
    break;
  case 2:
    addNode();
    break;
    case 3:
    deleteNode();
    break;
  case 4:
    displayNode();
    break;
  case 5:
    modifynode();
    break;
  case 6:
    purgeNode();
      break;
   case 7:
    searchNode();
    break;
  default:
    return;
  }
}

void printMenu() {
  cout << "\n--------------------------------" << endl;
  cout << "         Menu Prompt" << endl;
  cout << "--------------------------------" << endl;
  cout << "1. Create a List " << endl;
  cout << "2. Add a Node " << endl;
  cout << "3. Delete a Node " << endl;
  cout << "4. Display a Node " << endl;
  cout << "5. Modify a Node " << endl;
  cout << "6. Purge the List " << endl;
  cout << "7. Search for a Node " << endl;
  cout << "8. Restart the program or exit\n" << endl;
}

void validateMenuOption(int &selection) {
  if (selection < 0 || 8 < selection) {
    cout << "Please enter a digit between 0 and 6: ";
    cin >> selection;
  }
}

// allows the user to enter an integer selection they want.
void getMenuOption(int &selection) {
  cout << "Enter your selection: ";
  // cin.clear();
  cin >> selection;
  validateMenuOption(selection);
}

int main() {

  int selection;
  int restart;

  do {
    cout << "\n\n\nWelcome to Link List Programming!" << endl;
    cout << "Currently, no linked list exists.\n" << endl;

    do {
      printMenu();
      getMenuOption(selection);
      executeSelection(selection);
    } while (selection != 8);
    cout << "Enter 1 to restart or enter 0 to exit: ";
    cin >> restart;
  } while (restart == 1);

  return 0;
}















// #include <cstring>
// #include <fstream>
// #include <iomanip>
// #include <iostream>
// #include <limits>
// #include <string>

// using namespace std;

// struct node {
//   double id = 0;
//   string name = "";
//   double gpa = 0;
//   node *nxt;
// };

// // node createNode1();
// void createNode();
// // void printList();
// int checkStudentId(int);
// void enterNodeInfo(struct node *);
// bool noShell = true;
// bool emptyShell = true;
// struct node *start;
// struct node *current;
// struct node *previous;
// struct node *temp;

// void createNode() {
//   if (noShell) {
//     struct node *start = NULL;
//     struct node *current = NULL;
//     struct node *previous = NULL;
//     struct node *temp = NULL;
//     current = start;
//     temp = current->nxt;
//     noShell = false;
//     cout << "Linked list is created." << endl;
//   } else {
//     cout << "The linked list has already been created." << endl;
//   }
// }

// // void deleteNode()
// // {
// //   if(start==NULL)
// //   {
// //     cout << "No nodes to be deleted.";

// //   }
// //   else{
// //     double deleteid;
// //     cout << "Please enter the ID of the node that you want to delete: ";
// //     cin >> deleteid;
// //     current = start;
// //     while (current-> id != deleteid)
// //       {
// //         current = current -> nxt;
// //          if (current == NULL)
// //          {
// //          cout << "No matching ID." << endl;
// //            break;
// //           }

// //       }

// //      if (current == start)
// //     {
// //     temp= start;
// //     temp = temp->nxt;
// //     start = temp;
// //     delete current;
// //     cout << "Node successfully deleted";

// //     }
// //     else if (current->nxt == NULL)
// //     {
// //       previous = start;
// //         while (previous->nxt != current)
// //           {
// //             previous = previous -> nxt;
// //           }
// //         previous -> nxt = NULL ;
// //         delete current;
// //       cout << "Node successfully deleted";
// //       }
// //       else
// //       {
// //         previous = start;
// //         while (previous->nxt != current)
// //           {
// //             previous = previous -> nxt;
// //           }
// //         temp =start;
// //         while (current->nxt != temp)
// //           {
// //             temp = temp->nxt;
// //           }
// //         previous -> nxt = temp;
// //         delete current;
// //         cout << "Node successfully deleted";
// //       }
// //   }

// //     }

// void modifynode() {
//   double modifyid;
//   if (start == NULL) {
//     cout << "No nodes to be modified";
//   } else {
//     cout << "Please enter the ID of the node that you would like to modify:";
//     cin >> modifyid;
//     temp = start;
//     while (temp != NULL) {
//       if (temp->id == modifyid) {
//         cout << "You are allowed to modify only the GPA and the name." << endl;
//         cout << "ID: " << temp->id << "  |  ";
//         cout << "New GPA: ";
//         cin >> temp->gpa;
//         cout << "  |  ";
//         cout << "New Name: ";
//         cin >> temp->name;
//         cout << "Node successfulyy modified.";

//         cout << endl;
//         break;
//       } else {
//         temp = temp->nxt;
//         if (temp == NULL)
//           cout << "No Matching ID Exists\n";
//       }
//     }
//   }
// }

// // void emptyness(){ //I will add this to functions!
// //   if (start == NULL)
// //     emptyShell = true;
// //     else
// //      emptyShell = false;
// // }

// // struct node *start, struct node *current, struct node *prev
// void addNode() {
//   // emptyness();
//   if (noShell) {
//     cout << "Please create a linked list first." << endl;
//   } else {
//     node *s;
//     s = new node;

//     enterNodeInfo(s);

//     double studentId = s->id;
//     current = start;
//     while (current->id < studentId && current != NULL) {
//       previous = current;
//       current = current->nxt;
//     }
//     if (current == start) {
//       s->nxt = start;
//       start = s;
//     } else {
//       previous->nxt = s;
//       s->nxt = current;
//     }
//     cout << "A new list is added." << endl;
//     cout << "Start pointer points : " << start->id << endl;
//     emptyShell = false;
//   }
// }

// void enterNodeInfo(struct node *s) {
//   int studentId;
//   string realName;
//   cout << "Please enter an Id: ";
//   cin >> studentId;
//   temp = start;
//   studentId = checkStudentId(studentId);
//   s->id = studentId;
//   cin.ignore();
//   cout << "Please enter the person's name: ";
//   getline(cin, realName);
//   s->name = realName;
//   cout << "Please enter the person's GPA: ";
//   cin >> s->gpa;
//   s->nxt = NULL;
// }

// int checkStudentId(int studentId) {
//   temp = start;
//   while (temp != NULL) {
//     if (temp->id == studentId) {
//       cout << "You have already used this ID. Please enter a different ID."
//            << endl;
//       cin >> studentId;
//       // cin.ignore();
//     } else {
//       temp = temp->nxt;
//     }
//   }
//   // cin.ignore();
//   return studentId;
// }

// void searchNode() {
//   // emptyness();
//   if (noShell) {
//     cout << "Please create a linked list first." << endl;
//   } else if (emptyShell) {
//     cout << "Linked list is empty." << endl;
//   } else {
//     double searchID;
//     cout << "Please enter an Id that you are looking for : ";
//     cin >> searchID;
//     temp = start;
//     while (temp != NULL) {
//       if (temp->id == searchID) {
//         cout << "ID: " << setw(5) << temp->id << "  |  ";
//         cout << "GPA: " << setw(4) << temp->gpa << "  |  ";
//         cout << "Name: " << temp->name << endl;
//         break;
//       } else {
//         temp = temp->nxt;
//         if (temp == NULL)
//           cout << "No Matching ID Exists\n";
//       }
//     }
//   }
// }

// void displayNode() {
//   // emptyness();
//   if (noShell) {
//     cout << "Please create a linked list first." << endl;
//   } else if (emptyShell) {
//     cout << "Linked list is empty." << endl;
//   } else {
//     node *newDisplay = start;
//     while (newDisplay) {
//       cout << "ID: " << setw(5) << newDisplay->id << "  |  ";
//       cout << "GPA: " << setw(4) << newDisplay->gpa << "  |  ";
//       cout << "Name: " << newDisplay->name << endl;
//       newDisplay = newDisplay->nxt;
//     }
//   }
// }

// void purgeNode() {
//   // emptyness();
//   if (noShell) {
//     cout << "Please create a linked list first." << endl;
//   } else if (emptyShell) {
//     cout << "Linked list is empty." << endl;
//   } else {
//     current = start;
//     if (start->nxt == NULL) {
//       delete current;
//       start = NULL;
//       cout << "List is deleted\n";
//     } else {
//       while (start != NULL) {
//         start = current->nxt;
//         delete current;
//         current = start;
//         cout << "List is deleted\n";
//       }
//     }
//     cout << "The Node is successfully purged\n";
//   }
// }

// void executeSelection(int &selection) {
//   switch (selection) {
//   case 1:
//     createNode();
//     break;
//   case 2:
//     addNode();
//     break;
//   case 3:
//     // deleteNode();
//     break;
//   case 4:
//     displayNode();
//     break;
//   case 5:
//     modifynode();
//     break;

//   case 6:
//     purgeNode();
//     break;
//   case 7:
//     searchNode();
//     break;
//   default:
//     return;
//   }
// }

// // void Purge() {
// //   current = start;
// //   temp = start;
// //   if (start->nxt == NULL)
// //     delete temp;
// //   else {
// //     while(start->nxt == NULL)
// //       current->nxt;
// //       temp = current;
// //       temp->nxt;
// //       delete current;
// //     }
// // }

// void printMenu() {
//   cout << "\n--------------------------------" << endl;
//   cout << "         Menu Prompt" << endl;
//   cout << "--------------------------------" << endl;
//   cout << "1. Create a List " << endl;
//   cout << "2. Add a Node " << endl;
//   cout << "3. Delete a Node " << endl;
//   cout << "4. Display a Node " << endl;
//   cout << "5. Modify a Node " << endl;
//   cout << "6. Purge the List " << endl;
//   cout << "7. Search for a Node " << endl;
//   cout << "8. Restart the program or exit\n" << endl;
// }

// void validateMenuOption(int &selection) {
//   if (selection < 0 || 8 < selection) {
//     cout << "Please enter a digit between 0 and 6: ";
//     cin >> selection;
//   }
// }

// // allows the user to enter an integer selection they want.
// void getMenuOption(int &selection) {
//   cout << "Enter your selection: ";
//   // cin.clear();
//   cin >> selection;
//   validateMenuOption(selection);
// }

// int main() {

//   int selection;
//   int restart;

//   do {
//     cout << "\n\n\nWelcome to Link List Programming!" << endl;
//     cout << "Currently, no linked list exists.\n" << endl;

//     do {
//       printMenu();
//       getMenuOption(selection);
//       executeSelection(selection);
//     } while (selection != 8);
//     cout << "Enter 1 to restart or enter 0 to exit: ";
//     cin >> restart;
//   } while (restart == 1);

//   return 0;
// }

// // if (start -> id > s -> id || start = NULL) {
// //   s -> nxt = start;
// //   start = s;
// // }
// // if (startEmpty) {
// //   s -> nxt = start;
// //   start = s;
// //   current = s;
// //   startEmpty = false;
// // }
// // else {
// //   current = start;
// //     if(start != NULL) {
// //   while(current -> nxt != NULL){
// //     current = current -> nxt;
// //   }
// //   current -> nxt = s;
// //   current = s
// // }
// // temp -> nxt = current;
// // temp = temp -> nxt;

// // if(start != NULL) {

// //   while(current -> nxt != NULL && current -> id < ){
// //     current = current -> nxt;
// //   }
// //   current -> nxt = s;
// // }
// // else {
// //   start = s;
// // }
// // }

// // void deleteNode (int deleteData){
// //   nodePtr delPtr = NULL;
// //   temp = start;
// //   current = head;
// //   while(current != NULL && current -> id != delData) {
// //     temp = current;
// //     current = current -> nxt;
// //   }
// //   if(current == NULL) {        // When List is empty
// //     cout << delData << " was not in the list.";
// //     delete delPtr;
// //   }
// //   else {
// //     delPtr = current;
// //     current = current->nxt;
// //     temp -> nxt = current;
// //     delete delPtr;
// //     cout << "Value " << delData << " was deleted." << endl;
// //   }

// // }