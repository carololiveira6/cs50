// check50 cs50/problems/2024/x/credit

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int sum_digits(int num);
int process_credit_card_number(long card_number);
int is_valid_card(long card_number);
int count_digits(long number);
const char* get_card_type(long card_number);

int main(void)
{
    long card_number;

    card_number = get_long("Insert card number: ");

    int digit_count = count_digits(card_number);
    long prefix = card_number;
    const char* card_type = get_card_type(card_number);
    int is_valid = is_valid_card(card_number);

    if (is_valid && strcmp(card_type, "American Express") == 0)
    {
        printf("AMEX\n");
    }
    else if (is_valid && strcmp(card_type, "MasterCard") == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (is_valid && strcmp(card_type, "Visa") == 0)
    {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}

int sum_digits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int is_valid_card(long card_number)
{
    int total_sum = process_credit_card_number(card_number);
    return (total_sum % 10 == 0);
}

const char* get_card_type(long card_number) {
    int digit_count = count_digits(card_number);
    long prefix = card_number;
    int first_two_digits = -1;

    while (prefix >= 100) {
        prefix /= 10;
    }
    first_two_digits = prefix;

    if ((first_two_digits == 34 || first_two_digits == 37) && digit_count == 15) {
        return "American Express";
    } else if ((first_two_digits >= 51 && first_two_digits <= 55) && digit_count == 16) {
        return "MasterCard";
    } else {
        prefix /= 10; // Reduz prefixo para obter primeiro dígito
        if (prefix == 4 && (digit_count == 13 || digit_count == 16)) {
            return "Visa";
        }
    }
    return "INVALID";
}


int process_credit_card_number(long card_number)
{
    int sum = 0;
    int is_second = 0; // Usado para alternar entre os dígitos

    // Itera enquanto houver dígitos no número do cartão
    while (card_number > 0)
    {
        int digit = card_number % 10; // Extrai o último dígito
        card_number /= 10;            // Remove o último dígito

        if (is_second)
        {
            // Multiplica cada segundo dígito por 2 e soma os dígitos do produto
            int product = digit * 2;
            sum += sum_digits(product);
        }
        else
        {
            // Soma os dígitos que não foram multiplicados por 2
            sum += digit;
        }

        // Alterna entre os dígitos
        is_second = !is_second;
    }

    return sum;
}
// Função para contar o número de dígitos
int count_digits(long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}
