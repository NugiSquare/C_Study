int main(void)
{
	int price, num_coins;
	scanf("%d", &price);
	
	num_coins = price/500;
	price = price % 500;
	num_coins = num_coins + price/100;
	price = price % 100;
	num_coins = num_coins + price/50;
	price = price % 50;
	num_coins = num_coins + price/10;
	price = price % 10;
	
	printf("%d", num_coins);
	return 0;
}
