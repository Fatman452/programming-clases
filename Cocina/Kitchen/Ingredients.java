package Kitchen;

public class Ingredients {
	private String name;
	private int amountInGrams;
	private double priceIngredient;
	
	public Ingredients(String name, int amountInGrams, double priceIngredient) {
		super();
		this.name = name;
		this.amountInGrams = amountInGrams;
		this.priceIngredient = priceIngredient;
	}

	public String getName() {
		return name;
	}

	public int getAmountInGrams() {
		return amountInGrams;
	}

	public double getPriceIngredient() {
		return priceIngredient;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAmountInGrams(int amountInGrams) {
		this.amountInGrams = amountInGrams;
	}

	public void setPriceIngredient(float priceIngredient) {
		this.priceIngredient = priceIngredient;
	}
	
	
	
	
}
