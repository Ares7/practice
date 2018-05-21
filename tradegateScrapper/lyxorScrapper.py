import requests
from bs4 import BeautifulSoup
import csv
from datetime import datetime
#21,94,91
import os

quote_page = 'http://www.tradegate.de/orderbuch.php?lang=en&isin=LU0496786574'
response = requests.get(quote_page)

soup = BeautifulSoup(response.content, "html.parser")

price_bid = soup.find('tr', attrs={'class': 'Bid'})
price_bid = price_bid.text[4:].strip()

price_ask = soup.find_all('tr', attrs={'class': 'Ask'})
price_ask = price_ask[1].text[4:].strip()

bidsize = soup.find('td', attrs={'id': 'bidsize'}).text
asksize = soup.find('td', attrs={'id': 'asksize'}).text

highDay = soup.find('td', attrs={'id': 'high'}).text
lowDay = soup.find('td', attrs={'id': 'low'}).text


# print(price_bid)
# print(price_ask)
# print(bidsize)
# print(asksize)

# print(highDay)
# print(lowDay)

with open('index.csv', 'a') as csv_file:
	writer = csv.writer(csv_file)
	writer.writerow(["StockName", "DateTime", 
		"price_bid",  "price_ask", "bid_size", "ask_size", 
		"highDay", "lowDay"])
	writer.writerow(["MUL-Lyxor ETF S&P 500",datetime.now(), 
		price_bid,  price_ask, bidsize, asksize, highDay, lowDay])

