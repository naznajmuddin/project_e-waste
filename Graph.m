in=importdata('data1.txt')
out=importdata('data2.txt')
diff=importdata('data3.txt')

figure(1);
bar(out(:,1),out(:,2))
title('Total of e-Waste in Kuala Lumpur city (2016-2019)')
xlabel('Year')
ylabel('Total of e-Waste (Metric Tonne)')

figure(2);
bar(in(:,1),in(:,2:8))
title('Total of e-Waste according to types in Kuala Lumpur city (2016-2019)')
xlabel('Year')
ylabel('Total of e-Waste (Metric Tonne)')
legend('TV','PC','Cellphones','Refridgerator','Airconditioner','Washing Machine','Rechargeable Batteries')

figure(3);
bar(diff(:,1),diff(:,2))
title('Differences of total e-Waste between two years in Kuala Lumpur city')
xlabel('Year (16&17, 17&18, 18&19)')
ylabel('Total differences')