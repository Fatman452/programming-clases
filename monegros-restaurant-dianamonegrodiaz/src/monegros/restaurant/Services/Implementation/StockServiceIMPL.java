package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Stock;
import monegros.restaurant.entities.repository.IStockRepository;
import monegros.restaurant.services.interfaces.IStockService;

public class StockServiceIMPL implements IStockService{
private final IStockRepository stockRepository;
	
	public StockServiceIMPL(IStockRepository stockRepository) {
		this.stockRepository=stockRepository;
	}
	@Override
	public Optional<Stock> insert(Stock stock) {
		return this.stockRepository.insert(stock);
	}
	@Override
	public Optional<Stock> findById(Long id) {
		return this.stockRepository.findById(id);
	}
}
