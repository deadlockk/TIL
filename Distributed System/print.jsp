applicationContext.xml

<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
	xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	xsi:schemaLocation="http://www.springframework.org/schema/beans
        http://www.springframework.org/schema/beans/spring-beans.xsd">


	<bean id="car1" class="myPackage.CarFactory"
		factory-method="makeCar">
		<constructor-arg value="Sonata" />
		<constructor-arg value="2011" />
	</bean>
	<bean id="car2" class="myPackage.CarFactory"
		factory-method="makeCar">
		<constructor-arg value="A5" />
		<constructor-arg value="2010" />
	</bean>
	<bean id="car3" class="myPackage.CarFactory"
		factory-method="makeCar">
		<constructor-arg value="Avante" />
		<constructor-arg value="2009" />
	</bean>

	<bean id="employee1" class="myPackage.Employee">
		<constructor-arg value="13307" />
		<constructor-arg value="TaePyeong" />
		<constructor-arg>
			<list>
				<ref bean="car1" />
				<ref bean="car2" />
				<ref bean="car3" />
			</list>
		</constructor-arg>
		
	</bean>

	<bean id="employee2" class="myPackage.Employee">
		<constructor-arg value="1004" />
		<constructor-arg value="Gachon" />
		<constructor-arg>
			<list>
				<ref bean="car1" />
			</list>
		</constructor-arg>
	</bean>

	<bean id="employee3" class="myPackage.Employee">
		<property name="id" value="201333474" />
		<property name="name" value="Sang" />
		<property name="cars">
			<list>
				<ref bean="car1" />
				<ref bean="car2" />
			</list>
		</property>
	</bean>

	<bean id="employee4" class="myPackage.Employee">
		<property name="id" value="4490" />
		<property name="name" value="Mr.Phone" />
		<property name="cars">
			<list>
				<ref bean="car1" />
				<ref bean="car2" />
			</list>
		</property>
	</bean>

</beans>
