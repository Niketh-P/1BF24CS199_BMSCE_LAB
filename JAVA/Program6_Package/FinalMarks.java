package Program6_Package;
import java.util.*;
import Program6_Package.CIE.*;
import Program6_Package.SEE.*;
public class FinalMarks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        Student[] s = new Student[n];
        Internals[] in = new Internals[n];
        External[] ex = new External[n];
        for(int i = 0; i < n; i++){
            System.out.println("\nEnter details of student " + (i+1));
            System.out.print("USN: ");
            String usn = sc.next();
            System.out.print("Name: ");
            String name = sc.next();
            System.out.print("Semester: ");
            int sem = sc.nextInt();
            s[i] = new Student(usn, name, sem);
            System.out.println("Enter 5 Internal Marks:");
            int im[] = new int[5];
            for(int j = 0; j < 5; j++)
                im[j] = sc.nextInt();
            in[i] = new Internals(im);
            System.out.println("Enter 5 SEE Marks:");
            int em[] = new int[5];
            for(int j = 0; j < 5; j++)
                em[j] = sc.nextInt();
            ex[i] = new External(usn, name, sem, em);
        }
        System.out.println("\nFINAL MARKS OF STUDENTS");
        for(int i = 0; i < n; i++){
            System.out.println("\nStudent: " + s[i].name + "  (" + s[i].usn + ")");

            for(int j = 0; j < 5; j++){
                int finalMarks = in[i].internalMarks[j] + (ex[i].externalMarks[j] / 2);
                System.out.println("Course " + (j+1) + ": " + finalMarks);
            }
        }
    }
}
