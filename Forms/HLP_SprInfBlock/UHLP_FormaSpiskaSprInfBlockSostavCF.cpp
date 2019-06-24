#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaSpiskaSprInfBlockSostavCF.h"   
#include "UHLP_FormaSpiskaSprInfBlockSostavImpl.h"  
#include "IHLP_FormaSpiskaSprInfBlockSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaSpiskaSprInfBlockSostavCF::THLP_FormaSpiskaSprInfBlockSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaSpiskaSprInfBlockSostavCF::~THLP_FormaSpiskaSprInfBlockSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaSpiskaSprInfBlockSostavImpl * ob=new THLP_FormaSpiskaSprInfBlockSostavImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
