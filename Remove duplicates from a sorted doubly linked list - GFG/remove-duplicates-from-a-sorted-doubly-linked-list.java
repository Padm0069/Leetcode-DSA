//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.math.*;

class Node
{
	int data;
	Node next;
	Node prev;
	Node(int data)
	{
	    this.data = data;
	    next = prev = null;
	}
}

class DLinkedList
{
	
	Node newNode(Node head, int data)
	{
		Node n = new Node(data);
		if(head == null)
		{
		    head = n;
		    return head;
		}
		head.next = n;
		n.prev = head;
		head = n;
		return head;
	}
	
	
	void printList(Node head)
	{
    if (head == null)
       System.out.print("-1");
 
    while (head != null) {
        System.out.print(head.data + " ");
        head = head.next;
    }
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		DLinkedList DLL = new DLinkedList();
		int t = sc.nextInt();
		
		while(t>0)
		{
			Node temp;
			Node head = null;
			Node root = null;
			int n = sc.nextInt();
			for(int i=0;i<n;i++)
			{
				int x = sc.nextInt();
				head = DLL.newNode(head,x);
			    if(root == null)    root = head;
			}
			head = root;
			
		
		    GfG g = new GfG();
		    g.removeDuplicates(head);
			
			DLL.printList(head);
		    System.out.println();
		    t--;
		}
	}
}


// } Driver Code Ends


//User function Template for Java

/* Structure of Doubly Linked List
class Node
{
	int data;
	Node next;
	Node prev;
	Node(int data)
	{
	    this.data = data;
	    next = prev = null;
	}
}*/

class GfG
{
    void removeDuplicates(Node head)
	{
		// Your code here
		Node temp = head;

     Node temp1 = head;

     

     while(temp1 != null){

         if(temp.data == temp1.data){

             temp1 = temp1.next;

         }

         else{

             temp = temp.next;

             temp.data = temp1.data;

         }

     }

     temp.next=null;
	}
}
