package Kitchen;

public class Comida {
	private String nombre;
	private Ingredients[] ingredients;
	private int preparationTime;
	private float price;
	private int amountIngredients;
	
	public Comida(String nombre, int preparationTime, float price) {
		super();
		this.nombre = nombre;
		this.preparationTime = preparationTime;
		this.price = price;
		this.ingredients=new Ingredients[25];
		
	}

	/*public void ComidaIngredients(Ingredients ingredients) {
		this.ingredients[amountIngredients]= ingredients;
		amountIngredients++;
	}*/

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Ingredients[] getIngredients() {
		return ingredients;
	}
	public void setIngredients(Ingredients[] ingredients,int amount) {
		this.amountIngredients=amount;
		this.ingredients = ingredients;
	}

	public int getPreparationTime() {
		return preparationTime;
	}

	public void setPreparationTime(int preparationTime) {
		this.preparationTime = preparationTime;
	}

	public float getPrice() {
		return price;
	}

	public void setPrice(float price) {
		this.price = price;
	}

	public int getAmountIngredients() {
		return amountIngredients;
	}
	
}
