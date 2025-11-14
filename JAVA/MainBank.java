import java.util.*;

class Account {
    String customerName;
    int accountNumber;
    String accountType;
    double balance;

    void getAccountDetails(Scanner s) {
        System.out.print("Enter customer name: ");
        customerName = s.nextLine();

        System.out.print("Enter account number: ");
        accountNumber = s.nextInt();
        s.nextLine(); 

        System.out.print("Enter type of account (saving/current): ");
        accountType = s.nextLine();

        balance = 0;
    }

    void display() {
        System.out.println("\nCustomer Name : " + customerName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Type : " + accountType);
        System.out.printf("Balance : %.2f\n", balance);
    }
}



class Sav_acct extends Account {

    void deposit(Scanner s) {
        System.out.print("Enter deposit amount: ");
        double amount = s.nextDouble();

        if (amount <= 0) {
            System.out.println("Deposit must be positive!");
            return;
        }

        balance += amount;
        System.out.printf("Deposited %.2f, New Balance = %.2f\n", amount, balance);
    }

    void withdraw(Scanner s) {
        System.out.print("Enter withdrawal amount: ");
        double amount = s.nextDouble();

        if (amount <= 0) {
            System.out.println("Withdrawal must be positive!");
            return;
        }

        if (amount > balance) {
            System.out.println("Insufficient balance!");
        } else {
            balance -= amount;
            System.out.printf("Withdrew %.2f, New Balance = %.2f\n", amount, balance);
        }
    }

    void computeInterest(Scanner s) {
        System.out.print("Enter annual interest rate (e.g., 5 for 5%): ");
        double rate = s.nextDouble();

        System.out.print("Enter time period in years: ");
        int time = s.nextInt();

        if (rate <= 0 || time <= 0) {
            System.out.println("Rate and time must be positive!");
            return;
        }

        double principal = balance;
        double amount = principal * Math.pow((1 + rate / 100.0), time);
        double interest = amount - principal;
        interest = Math.round(interest * 100.0) / 100.0;

        balance += interest;

        System.out.printf("Interest added: %.2f, New Balance = %.2f\n", interest, balance);
    }
}



class Cur_acct extends Account {
    final double minBalance = 500;
    final double serviceCharge = 100;

    void deposit(Scanner s) {
        System.out.print("Enter deposit amount: ");
        double amount = s.nextDouble();

        if (amount <= 0) {
            System.out.println("Deposit must be positive!");
            return;
        }

        balance += amount;
        System.out.printf("Deposited %.2f, New Balance = %.2f\n", amount, balance);
    }

    void withdraw(Scanner s) {
        System.out.print("Enter withdrawal amount: ");
        double amount = s.nextDouble();

        if (amount <= 0) {
            System.out.println("Withdrawal must be positive!");
            return;
        }

        if (amount > balance) {
            System.out.println("Insufficient balance!");
            return;
        }

        balance -= amount;
        System.out.printf("Withdrew %.2f, Balance = %.2f\n", amount, balance);

        checkMinBalance();
    }

    void checkMinBalance() {
        if (balance < minBalance) {
            balance -= serviceCharge;
            if (balance < 0) balance = 0;

            System.out.printf("Balance below minimum! Service charge of %.2f imposed.\n", serviceCharge);
            System.out.printf("New Balance = %.2f\n", balance);
        } else {
            System.out.println("Minimum balance requirement satisfied.");
        }
    }
}



public class MainBank {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Sav_acct sav = new Sav_acct();
        Cur_acct cur = new Cur_acct();

        System.out.println("=== Create Savings Account ===");
        sav.getAccountDetails(s);
        sav.accountType = "saving";

        System.out.println("\n=== Create Current Account ===");
        cur.getAccountDetails(s);
        cur.accountType = "current";

        int choice;
        do {
            System.out.println("\n--- Main Menu ---");
            System.out.println("1. Savings Deposit");
            System.out.println("2. Savings Withdraw");
            System.out.println("3. Savings Compute Interest");
            System.out.println("4. Savings Display Details");
            System.out.println("5. Current Deposit");
            System.out.println("6. Current Withdraw");
            System.out.println("7. Current Display Details");
            System.out.println("8. Exit");

            System.out.print("Enter your choice: ");
            choice = s.nextInt();

            switch (choice) {
                case 1:
                    sav.deposit(s);
                    break;
                case 2:
                    sav.withdraw(s);
                    break;
                case 3:
                    sav.computeInterest(s);
                    break;
                case 4:
                    sav.display();
                    break;
                case 5:
                    cur.deposit(s);
                    break;
                case 6:
                    cur.withdraw(s);
                    break;
                case 7:
                    cur.display();
                    break;
                case 8:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 8);

        s.close();
    }
}
