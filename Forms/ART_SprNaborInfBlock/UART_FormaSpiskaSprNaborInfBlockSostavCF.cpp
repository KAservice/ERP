#include "vcl.h"
#pragma hdrstop  
#include "UART_FormaSpiskaSprNaborInfBlockSostavCF.h"   
#include "UART_FormaSpiskaSprNaborInfBlockSostavImpl.h"  
#include "IART_FormaSpiskaSprNaborInfBlockSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_FormaSpiskaSprNaborInfBlockSostavCF::TART_FormaSpiskaSprNaborInfBlockSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_FormaSpiskaSprNaborInfBlockSostavCF::~TART_FormaSpiskaSprNaborInfBlockSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_FormaSpiskaSprNaborInfBlockSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_FormaSpiskaSprNaborInfBlockSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_FormaSpiskaSprNaborInfBlockSostavImpl * ob=new TART_FormaSpiskaSprNaborInfBlockSostavImpl();  
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
