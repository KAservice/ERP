#include "vcl.h"
#pragma hdrstop  
#include "UART_FormaElementaSprInfBlockGrpCF.h"   
#include "UART_FormaElementaSprInfBlockGrpImpl.h"  
#include "IART_FormaElementaSprInfBlockGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_FormaElementaSprInfBlockGrpCF::TART_FormaElementaSprInfBlockGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_FormaElementaSprInfBlockGrpCF::~TART_FormaElementaSprInfBlockGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_FormaElementaSprInfBlockGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_FormaElementaSprInfBlockGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_FormaElementaSprInfBlockGrpImpl * ob=new TART_FormaElementaSprInfBlockGrpImpl();  
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
