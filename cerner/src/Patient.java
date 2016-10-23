import java.util.List;

public class Patient {

private String name;

private int age;

private List<Allergy> allergyList; 

private List<Disease> diseaseList;


public String getName() {
return name;
}

public void setName(String name) {
this.name = name;
}

public int getAge() {
return age;
}

public void setAge(int age) {
this.age = age;
}

public List<Allergy> getAllergyList() {
return allergyList;
}

public void setAllergyList(List<Allergy> allergyList) {
this.allergyList = allergyList;
}

public List<Disease> getDiseaseList() {
return diseaseList;
}

public void setDiseaseList(List<Disease> diseaseList) {
this.diseaseList = diseaseList;
}
}