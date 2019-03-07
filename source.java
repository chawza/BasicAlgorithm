/*
 * Name			: Nabeel Kahlil Maulana
 * NIM			: 2201773134
 * program name	: Book storage stock manager
 * 
 * features:
 * 1. show All books in storage
 * 2. add new Books to storage
 * 3. add stock on existing books
 * 4. subtract stock on existing books
 * 5. check duplications
 * 6. clarity menu (uses blank spaces)
 * 7. class objects inside arrayList
 * 
 * github: https://github.com/chawza
 */

import java.util.ArrayList;
import java.util.Scanner;

/*
 things that need to get done:
	1. coming soons
 */

class StorageBook {
	String name;
	int stock;
	
	StorageBook (String nameInput, int numInput) {
		name = nameInput;
		stock = numInput;
	}
	
	void addStock(int numAdd) {
		stock += numAdd;
	}
	
	void subStock(int numInput) {
		stock -= numInput;
	}
}

public class source{
	static Scanner scan = new Scanner(System.in);
	static ArrayList<StorageBook> book = new ArrayList<StorageBook>();
	
	public static void main(String[] args) {
		
		//default storage capacity
		book.add(new StorageBook("Wheel of Time", 20));
		book.add(new StorageBook("Oliver Twists", 15));
		book.add(new StorageBook("Frankenstain", 27));
		
		
		int bookIdx;
		int menuInput = 0;
		while(menuInput != 5) {
			printBooks();
			System.out.println("\nMenu:");
			System.out.println("1. Show all Books in storage\n2. Add new books to storage\n3. Add stock to existing books\n4. Subract stock from existing books\n5. Exits program");
			System.out.print("User Choice: ");
			menuInput = scan.nextInt();
			scan.nextLine();
			
			switch (menuInput) {
				case 1:		//skips everything to show books
					printBlanks();
					printBooks();
					System.out.println("press enter to continue...");
					scan.nextLine();
					break;
					
				case 2:		//if the user choose to add new Books to the storage
					System.out.print("Please insert new book title: ");
					
					//user input book title
					String newBookInp;		// book length can only under 30 characters
					do {
						newBookInp = scan.nextLine();
						if(newBookInp.length() > 30 || newBookInp.length() < 8) {
							System.out.println("Book title length range is 8 to 29!\nPlease re-input book title!");
						}
					}while(newBookInp.length() > 30 || newBookInp.length() < 8);
					
					System.out.print("Please add amount of book to add: ");
					int newBookStock = scan.nextInt();
					scan.nextLine();
					
					if(checkDuplication(newBookInp)) {
						int inpIdx = findBookIdx(newBookInp);
						book.get(inpIdx-1).addStock(newBookStock);
					}
					else {
						addNewBooks(newBookInp, newBookStock);
					}
					break;
					
				case 3:		//if the user add the stock to existing books
					printBlanks();
					if(!printBooks()) {
						break;
					}
					
					System.out.println("\nPlease choose the book to add based on index: ");
					bookIdx = scan.nextInt();
					scan.nextLine();
					System.out.println("Please input the number of book to add: ");
					int numAdd = scan.nextInt();
					scan.nextLine();
					
					book.get(bookIdx-1).stock  += numAdd;
					break;
					
				case 4:		//if the user subtract the stock to existing books
					printBlanks();
					if(!printBooks()) {
						scan.nextLine();
						break;
					}
					
					System.out.println("\nPlease choose the book to subtract based on index: ");
					bookIdx = scan.nextInt();
					scan.nextLine();
					System.out.println("Please input the number of book to subtract:");
					
					int numSub;
					do {
						numSub = scan.nextInt();
						scan.nextLine();
					} while (numSub >= book.get(bookIdx-1).stock);
					
					book.get(bookIdx-1).stock -= numSub;
					
					break;
					
				case 5:		//if the user choose to exits the program
					printBlanks();
					System.out.println("Thank you for using the program.");
					break;
					
				default:	//user choose the wrong input
					System.out.println("You chose the wrong input, please re-enter again!");
					break;		
			}
			printBlanks();
		}
		
	}
	
	//prints all available books
	static boolean printBooks() {
		//check whether books are available in the storage
		if(book.size() == 0) {	
			System.out.println("Ther are no book in the Storage!\nPlease add new book to add");
			return false;
		}
		
		System.out.println("Storage Books Premium: the best place to store books".toUpperCase());
		System.out.println("No.\tBook Title\t\tAvailable Stock");
		for(int a = 0; a < book.size(); a++) {
			System.out.println(a + 1 + "\t" + book.get(a).name + "\t\t" + book.get(a).stock);
		}
		return true;
	}
	
	//add new object and add it to the arraylist(book)
	static void addNewBooks(String newName, int newStock) {			
		StorageBook tempBook = new StorageBook(newName, newStock);
		System.out.println(tempBook.stock + " books of " + tempBook.name + " has been added to the storage");
		book.add(tempBook);
	}
	
	//just print newlines for clarity
	static void printBlanks() {	
		for(int a = 0; a < 15; a++) {
			System.out.println();
		}
	}
	
	//check if the book has already exists
	static boolean checkDuplication(String name) {
		
		for(int a = 0; a < book.size(); a++) {
			if(book.get(a).name.toLowerCase().equals(name.toLowerCase())) {
				System.out.println("the book is already added in the storage!");
				return true;
			}
		}
		return false;
	}
	
	static int findBookIdx(String name) {
		for(int a = 0; a < book.size(); a++) {
			if(book.get(a).name.toLowerCase().equals(name.toLowerCase())) {
				return (a+1);
			}
		}
		return 0;
	}
}