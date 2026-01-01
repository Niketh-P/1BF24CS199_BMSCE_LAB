create database telecom;
use telecom;

create table sim(
sim_No int(30),
customer_id varchar(30),
network_Technology varchar(20),
activation_Date date,
connection_Status varchar(15),
primary key(sim_No));

drop table sim;

create table serviceReq(
sim_No int(30),
request_No varchar(30),
request_Type varchar(20),
date_of_Request date,
resolution_Status varchar(50),
primary key(request_No),
foreign key(sim_No) references sim(sim_No));

drop table serviceReq;

insert into sim values
(10011001, 'Anjay', '5G', '2024-02-21', 'Connected'),
(10011002, 'Anand', '5G', '2024-03-14', 'Disconnected'),
(10011003, 'Pritam', '4G', '2024-07-16', 'Connected'),
(10011004, 'Nihal', '4G', '2024-10-25', 'Disconnected'),
(10011005, 'Niketh', '5G', '2024-12-03', 'Connected');

insert into serviceReq values
(10011001, '001', 'Connectivity issue', '2025-03-19', 'Completed'),
(10011001, '002', 'Slow Speed', '2025-03-20', 'In Progress'),
(10011002, '003', 'Connection Breach', '2025-04-10', 'Pending'),
(10011003, '004', 'Connectivity issue', '2025-04-22', 'In Progress'),
(10011004, '005', 'Connectivity issue', '2025-05-09', 'Completed'),
(10011005, '006', 'Slow Speed', '2025-06-30', 'In Progress'),
(10011005, '007', 'Connectivity issue', '2025-10-21', 'Pending');

select s2.request_No, s2.request_Type as 'service Requests', s1.customer_id as 'Customer Name' , s1.sim_No 
from sim s1, serviceReq s2
where s2.sim_No=s1.sim_No;

select request_No, request_Type, resolution_Status
from serviceReq
where resolution_Status in ('In Progress','Pending');
