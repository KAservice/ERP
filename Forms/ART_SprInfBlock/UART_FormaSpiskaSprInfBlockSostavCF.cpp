#include "vcl.h"
#pragma hdrstop  
#include "UART_FormaSpiskaSprInfBlockSostavCF.h"   
#include "UART_FormaSpiskaSprInfBlockSostavImpl.h"  
#include "IART_FormaSpiskaSprInfBlockSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_FormaSpiskaSprInfBlockSostavCF::TART_FormaSpiskaSprInfBlockSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_FormaSpiskaSprInfBlockSostavCF::~TART_FormaSpiskaSprInfBlockSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_FormaSpiskaSprInfBlockSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_FormaSpiskaSprInfBlockSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_FormaSpiskaSprInfBlockSostavImpl * ob=new TART_FormaSpiskaSprInfBlockSostavImpl();  
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
