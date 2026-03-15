

# stock problem

def buy_maximum_products(n: int, k: int, prices: list) -> int:
    temp = []
    for i in range(n):
        temp.append((prices[i], i+1))  # ith day stock price and max no of stocks that can be bought on ith day 
        
    # sort on stock price in increasing fashion. This ensures we get max no of stocks per unit price
    # lower the stock price, more is the value of # of stocks per unit price. Thus sorted in increasing order of stock price.
    temp.sort(key=lambda x: x[0])
    
    count = 0
    for stock_price, num_of_stocks in temp:
        
        # can I buy them all 
        if stock_price * num_of_stocks <= k:
            count += num_of_stocks
            k -= (stock_price * num_of_stocks)
        else:
            # If I cannot buy all, then I'll buy as much as possible
            count += (k // stock_price)
            
            # I cannot buy any futher -- hence break
            break    
        
    return count
        
# Time: O(nlog n)
# Space: O(n)
    
    