#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next = NULL;
};
class queue
{
	node *front;

	public:
		queue()
		{
			front = NULL;
		}
		bool isEmpty()
		{
			if (front == NULL)
			{
				return true;
			}
			return false;
		}
		int getFront()
		{
			return front->data;
		}
		void enqueue(int el)
		{
			node *newnode = new node;
			newnode->data = el;

			if (isEmpty())
			{
				front = newnode;
				return;
			}

			node *curr = front;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newnode;
		}
		int dequeue()
		{
			if (isEmpty())
			{
				return 0;
			}
			int item = front->data;

			node *temp = front;
			front = front->next;

			free(temp);

			return item;
		}
		void print()
		{
			node *curr = front;
			while (curr != NULL)
			{
				cout << curr->data << " ";
			}
			cout << endl;
		}
};

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void bubble(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
int main()
{
	cout << "Welcome to the LPT Printer Program!" << endl;

	queue q;
	int num;
	int i = 0;
	int *arr = new int[100];

	cout << "Enter the list of numbers you'd like to schedule. Seperate them by spaces or new lines. Enter -1 when finished." << endl;
	while (cin >> num)
	{
		if (num == -1)
		{
			break;
		}
		arr[i] = num;
		i++;
	}

	bubble(arr, i);

	for (int x = 0; x < i; x++)
	{
		q.enqueue(arr[x]);
	}

	int a[25];
	int b[25];
	int c[25];

	a[0] = q.dequeue();
	b[0] = q.dequeue();
	c[0] = q.dequeue();

	int numA = 0, numB = 0, numC=0;

	while (!q.isEmpty())
	{
		if (a[numA] <= b[numB])
		{
			if (c[numC] < a[numA])
			{
				c[numC + 1] = q.dequeue() + c[numC];
				numC++;
			}
			else
			{
				a[numA + 1] = q.dequeue() + a[numA];
				numA++;
			}
		}
		else
		{
			if (c[numC] < b[numB])
			{
				c[numC + 1] = q.dequeue() + c[numC];
				numC++;
			}
			else
			{
				b[numB + 1] = q.dequeue() + b[numB];
				numB++;
			}
		}
	}

	cout << "\nHere's our final schedule for the printers! \nNote that subsequent numbers represent the total time for the printer after adding a new task to the schedule." << endl;
	
	cout << "\nPrinter A: ";
	for (int u = 0; u < numA; u++)
	{
		cout << a[u] << " ";
	}
	cout << a[numA] << endl;

	cout << "Printer B: ";
	for (int u = 0; u < numB; u++)
	{
		cout << b[u] << " ";
	}
	cout << b[numB] << endl;

	cout << "Printer C: ";
	for (int u = 0; u < numC; u++)
	{
		cout << c[u] << " ";
	}
	cout << c[numC] << endl;
	
	return 0;
}