# TEST PLAN:

## Table no: High level test plan
   
| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       | Adding Medicine Record |  "Add_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" |"Add_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" | "Add_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" |Requirement based |
|  H_02       | Modify Medicine Record | "Modify1" |"Modify_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234"| "Modify_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" |Scenario based    |
|  H_03       | Delete Medicine Record | "Delete_1" |-------------|----------------|Boundary based    |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | Search Medicine Record | "Search_1" | "Search_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" | "Search_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234" |Requirement based |
|  L_02       | Display Medicine Record | "Displat_opt" | All Records | All Records |Scenario based    |

# Output

## Add Medicine
![image](https://github.com/karthi-koundinya/Stepin-Pharma-Store/blob/main/4_TestPlanAndOutput/addMedicine.jpg)

## Search and Delete Medicine
![image](https://github.com/karthi-koundinya/Stepin-Pharma-Store/blob/main/4_TestPlanAndOutput/SearchDelete.jpg)

## Modify Medicine

![image](https://github.com/karthi-koundinya/Stepin-Pharma-Store/blob/main/4_TestPlanAndOutput/Modify.jpg)

## Display Medicine

![image](https://github.com/karthi-koundinya/Stepin-Pharma-Store/blob/main/4_TestPlanAndOutput/Display.jpg)

