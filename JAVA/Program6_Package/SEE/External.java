package Program6_Package.SEE;
import Program6_Package.CIE.Student;
public class External extends Student {
    public int[] externalMarks = new int[5];
    public External(String usn, String name, int sem, int[] ext){
        super(usn, name, sem);
        for(int i = 0; i < 5; i++){
            externalMarks[i] = ext[i];
        }
    }
}
