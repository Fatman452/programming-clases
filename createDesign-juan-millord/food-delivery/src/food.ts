
export class Food {
  public name: string;
  public ingredients: string;
  public price: number;
  public type: string;
  public status: string

  get foodPrice() {
    return this.price;
  }

  set foodPrice(value: number) {
    if (value > 0) {
      this.price = value
    }
  }

  placeOrder() {
    // place the order
  }

  cook() {
    // cook the meal
  }

  getStatus() {
    // get the status of the meal
    return this.status;
  }
}