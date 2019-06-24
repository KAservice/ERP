#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprNaborInfBlockSostavCF.h"   
#include "UART_DMSprNaborInfBlockSostavImpl.h"  
#include "IART_DMSprNaborInfBlockSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavCF::TART_DMSprNaborInfBlockSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavCF::~TART_DMSprNaborInfBlockSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_DMSprNaborInfBlockSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprNaborInfBlockSostavImpl * ob=new TART_DMSprNaborInfBlockSostavImpl();  
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
