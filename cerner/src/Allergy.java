
public class Allergy {
	private String Allergyname;
	private String severity;
	public enum sever{
		BAD,GOOD;
	}
	sever tpe;
	public void setsever(sever tpe){
		this.tpe = tpe;
	}
	
	public void setname(String Allergyname){
		this.Allergyname = Allergyname;
	}
	
	public void setseverity(String severity){
		this.severity = severity;
	}
	
	public String getseverity(){
		return this.severity;
	}
	
	public String getname(){
		return this.Allergyname;
	}

}
