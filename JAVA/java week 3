import java.util.*;

public class Book{
    private String title;
    private String author;
    private double price;
    private int pg_no; 

    public Book(String title, String author, double price, int pg_no) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.pg_no = pg_no;
    }

    public void setname(String title) {
        this.title = title;
    }
    public void setauthor(String author) {
        this.author = author;
    }
    public void setprice(double price) {
        this.price = price;
    }
    public void setpg_no(int pg_no) {
        this.pg_no = pg_no;
    }
    public String getname() {
        return title;
    }
    public String getauthor() {
        return author;
    }
    public double getprice() {
        return price;
    }
    public int getpg_no() {
        return pg_no;
    }
    public String toString() {
        return "Title: " + title + 
        ",\n Author: " + author + 
        ",\n Price: " + price + 
        ",\n Pages: " + pg_no;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the number of books:");
        int n=sc.nextInt();

        sc.nextLine();


        Book[] books=new Book[n];

        for(int i=0;i<n;i++) {

            System.out.println("Enter the author of the book:");
            String author=sc.nextLine();
            

            System.out.println("Enter the title of the book: ");
            String title=sc.nextLine();
            
            System.out.println("Enter the price of the book:");
            double price=sc.nextDouble();

            System.out.println("Enter the number of pages of the book:");
            int pg_no=sc.nextInt();

            sc.nextLine();

            books[i]=new Book(title, author, price, pg_no);
        }

        for(Book b: books) {
            System.out.println(b.toString());

        }
    }
}
