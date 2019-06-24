#include "vcl.h"
#pragma hdrstop  
#include "UART_FormaElementaSprNaborInfBlockGrpCF.h"   
#include "UART_FormaElementaSprNaborInfBlockGrpImpl.h"  
#include "IART_FormaElementaSprNaborInfBlockGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TART_FormaElementaSprNaborInfBlockGrpCF::TART_FormaElementaSprNaborInfBlockGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TART_FormaElementaSprNaborInfBlockGrpCF::~TART_FormaElementaSprNaborInfBlockGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TART_FormaElementaSprNaborInfBlockGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TART_FormaElementaSprNaborInfBlockGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TART_FormaElementaSprNaborInfBlockGrpImpl * ob=new TART_FormaElementaSprNaborInfBlockGrpImpl();  
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
