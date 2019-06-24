#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprInfBlockPrivCF.h"   
#include "UART_DMSprInfBlockPrivImpl.h"  
#include "IART_DMSprInfBlockPriv.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprInfBlockPrivCF::TART_DMSprInfBlockPrivCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprInfBlockPrivCF::~TART_DMSprInfBlockPrivCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_DMSprInfBlockPrivCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprInfBlockPrivImpl * ob=new TART_DMSprInfBlockPrivImpl();  
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
