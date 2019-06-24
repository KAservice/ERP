#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaGurCustQueryDetalCF.h"   
#include "UREM_FormaGurCustQueryDetalImpl.h"  
#include "IREM_FormaGurCustQueryDetal.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaGurCustQueryDetalCF::TREM_FormaGurCustQueryDetalCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaGurCustQueryDetalCF::~TREM_FormaGurCustQueryDetalCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaGurCustQueryDetalCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaGurCustQueryDetalCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaGurCustQueryDetalImpl * ob=new TREM_FormaGurCustQueryDetalImpl();  
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
