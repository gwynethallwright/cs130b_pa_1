#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct node { 
   int coeff;
   int power; 
   struct node * next; 
}; 

void insert_at_end(struct node * prev, int new_coeff, int new_power) { 
   struct node * new_node = (struct node*) malloc(sizeof(struct node));
   new_node->coeff = new_coeff;
   new_node->power = new_power;
   new_node->next = NULL;
   prev->next = new_node;
}

void insert_in_middle(struct node * prev, int new_coeff, int new_power) { 
   struct node * new_node = (struct node*) malloc(sizeof(struct node));
   new_node->coeff = new_coeff;
   new_node->power = new_power;
   new_node->next = (prev->next)->next;
   prev->next = new_node;
}

void delete_in_middle(struct node * prev) {
   struct node * temp = prev->next;
   prev->next = (prev->next)->next;
   free(temp);
}

void delete_at_end(struct node * prev) {
   struct node * temp = prev->next;
   prev->next = NULL;
   free(temp);
}

void writePoly(struct node * head) { 
   struct node * ptr = head->next;
   while (ptr != NULL) { 
      cout << ptr->coeff << " " << ptr->power << " "; 
      ptr = ptr->next; 
   }
   cout << "\n";
}

/*
struct node * addPoly(struct node * poly_1, struct node * poly_2) {
   struct node * ptr_1 = poly_1->next;
   struct node * ptr_2 = poly_2->next;
   struct node * return_poly;
   struct node * ptr_3 = return_poly;
   insert_at_end(ptr_3, 40, 41);
   while ((ptr_1 != NULL) && (ptr_2 != NULL)) {
      insert_at_end(ptr_3, ptr_1->coeff, ptr_1->power);
      ptr_1 = ptr_1->next;
      ptr_2 = ptr_2->next;
      
      if ((ptr_1->power) < (ptr_2->power)){
         insert_at_end(ptr_3, ptr_1->coeff, ptr_1->power);
         ptr_1 = ptr_1->next;
      }
      else if ((ptr_2->power) < (ptr_1->power)){
         insert_at_end(ptr_3, ptr_2->coeff, ptr_2->power);
         ptr_2 = ptr_2->next;
      }
      else{
         insert_at_end(ptr_3, (ptr_1->power+ptr_2->power)%10000, (ptr_1->coeff+ptr_2->coeff)%1000000);
      }
      ptr_3 = ptr_3->next;
   }
   return return_poly;
}
*/

auto readPoly(string input){
  struct node * poly_1;
  struct node * poly_2;
  string current;
  istringstream iss(input);
  iss >> current;
  long power;
  int operation = 1;
  struct node * ptr = poly_1;
  while (iss){
    if (current == "+"){
      ptr = poly_2;
    }
    else if (current == "*"){
      ptr = poly_2;
      operation = 0;
    }
    else if (current == "**"){
      operation = 2;
      break;
    }
    else {
      iss >> power;
      insert_at_end(ptr, stoi(current), power);
      ptr = ptr->next;
    }
    iss >> current;
  }
  struct result {struct node * polynomial_1; struct node * polynomial_2; int operation;};
  return result {poly_1, poly_2, operation};
}

int main(int argc, char** argv) { 
   auto [poly_1, poly_2, operation] = readPoly(argv[1]);
   writePoly(poly_1);
   writePoly(poly_2);
   /*
   struct node * poly_3 = addPoly(poly_1, poly_2);
   if (operation == 0){
      cout << "case 0 ";
      poly_result = mulPoly(poly_1, poly_2);
   }
   else if (operation == 1){
      cout << "case 1 ";
      poly_3 = addPoly(poly_1, poly_2);
   }
   else {
      cout << "case 3 ";
      poly_result = sqPoly(poly_1);
   }
   writePoly(poly_result);
   struct node * ptr;
   head->coeff = 30;
   head->next = NULL;
   ptr = head;
   for (int i = 0; i < 10; ++i){
      insert_at_end(ptr, i, i);
      ptr = ptr->next;
   }
   delete_in_middle(head->next->next->next);
   delete_at_end(head->next->next->next->next->next->next);
   cout<<"The linked list is: ";
   */
   return 0;
} 