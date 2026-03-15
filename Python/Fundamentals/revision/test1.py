MMM, 

stage: -- e2open,
    internal_item_id ; unique indentifier of an item
    internal_store_id: unique identifier of a store
    

sales_exec.inv_mgmt_distbr_inv
plan_to_nbr,  --> foreign key
sold_to_nbr,    walmart_
matrl_nbr --> foreign key
brand_nm,
catg_nm,
distbr_nbr
edu_seg_cd --> K12, Schools, College
fisc_yr,
fisc_id,
fisc_wk: -- weekly grain 
dollar amt
on hand cases 
on order cases 


-- sap tables are being used 
-- sap ecc tables which basically acts as source for the cust_hier, matrl_hier
cust_sold_to:
    cust_nbr:
    cust_nm,
    plan_to-Nm,
    loc:
    rgn;
    state:
        
cust:
    cust_nbr:
    cust_nm,
    super_plan_to,
    plan_to,
    
    
        

matrl_mstr.matrl
    matrl_nbr:
    upc:
    internal_item_id:
    uom --> unit of measure cs, pkg, 
    
        
matrl_mstr.gtin:
    gtin:
    matrl_nbr
    matr_desc,
    brand_nm --> choco-krispie, eggos, rkt
    catg_nm, snacks

        

    
    
    



-- multiple warehouses 

wh_id: (PK)
whse_nm
upc,
uom --> cs, pkg, cartons
"cs on hand" --> fact column 
"risk $ amt" --> 
expiry_dt:
    

retil_info : ahold, costco, walmart etc 

cust_nbr, (PK)
# cust_nm,
# location,
# state, 
wh_id--> from which warheouse are we getting this product (FK)
uom --> cs, pkg, cartons
gtin, 
on_hnd_inv:
dollar_amt:
forecast_inv_wk1


s3
    kna 
        - npd 
        - prod
            s3 land layer -- where source files exist 
                -- src_nm (sap ecc)
                    -- dataset_nm

            s3 preproc layer 
            
                        
    keu
    kla
    kamea 
    global 
    
fucked up this round: neeed to focus on the data modelling part of differnt business domains
basically column level details


Questions asked in the final round of BCG with senior director:
    
1. Data Modelling
    pick any one business domain:
        like marketing exec, marketing cmpgn, sales_exec, sales_strat_plan etc 
        and design their models (field level info)
    what sources were used, their field info --> how did you model it to build your domain models for supporting the business function
    source tables --> domain tables --> datamarts --> what metrics are you tracking on dashboards etc?
    
    
2. Was grilled heavily on the architectural front:
    2.1 what happens if you receive 10GB of data at once in your land layer (1000 files basically) -- how will the ingestion process work in this case
    how each file is tracked and ingested into the final table.
    
    2.2 why do you have staging tables in snowflake. Isnt your data getting duplicated between s3 and snowflake staging?
    
    2.3 Implementation level details of iceberg tables. I talked about the new lakehouse architecture built using iceberg. Interviewer went into the implementation level details.
    
    2.4 What were the configurations of worker nodes used in Glue (worker node types and DPU ?). 
    How many worker nodes do you need in order to process 10 TB of data assuming auto scaling feature is not available. Actually I mentioned that in glue we have enabled auto scaling so based on the workload, glue will automatically provision reqired no of workers.OverflowError
    
    2.5 Why glue? why not EMR? In other words what advatanges were you getting by using glue over emr?
        I mentioned that in EMR -- we have more control over the cluster. Glue abstracts those details for us. There is more overhead in EMR. To which the interviewer countered, emr is also pretty straight forward. You just allocate the required no of instances. 
        
    
    
    
    