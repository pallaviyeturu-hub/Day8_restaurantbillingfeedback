#include <stdio.h>

int main() {
    int numCustomers, numItems, quantity, feedback;
    float price, subtotal, gst, totalBill;
    float totalRevenue = 0, totalFeedback = 0, highestBill = 0;
    
    printf("Enter number of customers: ");
    scanf("%d", &numCustomers);

    for(int i = 1; i <= numCustomers; i++) {
        printf("\nCustomer %d:\n", i);
        printf("Enter number of items: ");
        scanf("%d", &numItems);
        
        subtotal = 0;
        for(int j = 1; j <= numItems; j++) {
            printf("Enter price of item %d: ", j);
            scanf("%f", &price);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            
            subtotal += price * quantity;
        }

        gst = 0.05 * subtotal;
        totalBill = subtotal + gst;
        printf("Customer %d Bill: ₹%.2f\n", i, totalBill);
        
        printf("Enter feedback (1–5): ");
        scanf("%d", &feedback);
        
        // Validate feedback
        if(feedback < 1 || feedback > 5) {
            printf("Invalid feedback! Setting it to 3 by default.\n");
            feedback = 3;
        }

        totalFeedback += feedback;
        totalRevenue += totalBill;
        
        if(totalBill > highestBill)
            highestBill = totalBill;
    }

    printf("\n--- Restaurant Bill Summary ---\n");
    for(int i = 1; i <= numCustomers; i++) {
        // This is just for display, already shown above
    }

    printf("Total Revenue Today: ₹%.2f\n", totalRevenue);
    printf("Average Feedback Rating: %.2f\n", totalFeedback / numCustomers);
    printf("Highest Bill Amount: ₹%.2f\n", highestBill);

    return 0;
}