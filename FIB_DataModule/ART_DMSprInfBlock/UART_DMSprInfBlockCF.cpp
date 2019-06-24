#include "vcl.h"
#pragma hdrstop  
#include "UART_DMSprInfBlockCF.h"   
#include "UART_DMSprInfBlockImpl.h"  
#include "IART_DMSprInfBlock.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_DMSprInfBlockCF::TART_DMSprInfBlockCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_DMSprInfBlockCF::~TART_DMSprInfBlockCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_DMSprInfBlockCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_DMSprInfBlockCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_DMSprInfBlockCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_DMSprInfBlockCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_DMSprInfBlockImpl * ob=new TART_DMSprInfBlockImpl();  
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
