int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || pricesSize == 1) return 0;
    int min_buy_price = prices[0], max_profit = 0;
    
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < min_buy_price)
            min_buy_price = prices[i];
        if((prices[i] - min_buy_price)> max_profit)
            max_profit = prices[i] - min_buy_price;
    }
        return max_profit;
}