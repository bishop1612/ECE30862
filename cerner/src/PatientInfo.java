import java.util.ArrayList;
import java.util.List;
public class PatientInfo {

public static void main(String[] args) {
Patient pt = new Patient();
pt.setName("jack");
Allergy al = new Allergy();
al.setname("rashes");
al.setseverity("medium");
Allergy al1 = new Allergy();
al1.setname("swelling");
al1.setseverity("medium");
List<Allergy> allergyList = new ArrayList<Allergy>();
allergyList.add(al);
allergyList.add(al1);
pt.setAllergyList(allergyList);
String str = patient(pt);
System.out.println(" Result is :: " + str);


}

public static String patient(Patient pt){
	
if(pt.getAllergyList().size() > 0){
return "allergy";
}
else if (pt.getDiseaseList().size() > 0){
return "diease";
}
return null;
}

}